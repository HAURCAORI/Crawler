#include <iostream>
#include <sstream>
#include "htmlparser.h"
#include "stringextension.h"
#include "curltype.h"

#include "pugixml/pugixml.hpp"

#define RAPIDJSON_HAS_STDSTRING 1
#include <rapidjson/document.h>
#include <rapidjson/pointer.h>

#include "conversion.h"

void rightEndSpace(std::string::iterator& it) {
    while(*(it+1) == ' ' || *(it+1) == '\n') { ++it; }
}

void leftEndSpace(std::string::iterator& it) {
    while(*(it-1) == ' ' || *(it-1) == '\n' || *(it-1) == '\t') { --it; }
}

void continueUntilChar(std::string::iterator& it) {
    while(isSpace(*it)) { ++it; }
}

void removeSpace(std::string& str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
}

std::string indent(int depth) {
    return std::string(std::max(depth-1,0), '\t');
}

std::string popStringLine(std::string& str) {
    if(str.empty()) { return std::string(); }
    for(auto it = str.begin(); it != str.end(); ++it) {
        if(*it == '\n') {
            std::string temp = std::string(str.begin(), it);
            str.erase(str.begin(), it + 1);
            return temp;
        }
    }
    std::string temp(str);
    str.erase(str.begin(), str.end());
    return temp;
}

namespace Crawler {

HTTPResponse::HTTPResponse(const std::string& line) {
    if(line.empty()) { return; }
    size_t pos_start = 0, pos_end;
    pos_end = line.find(' ', pos_start);

    if(pos_end != std::string::npos) {
        protocol = line.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + 1;
    }

    std::string code, status;
    pos_end = line.find(' ', pos_start);
    if(pos_end != std::string::npos) {
        code = line.substr(pos_start, pos_end - pos_start);
        status = line.substr(pos_end + 1);
        statusCode = std::make_pair(atoi(code.c_str()), status);
    }
}

bool HTTPResponse::findHeader(const std::string& header) {
    return headers.find(TrimAndLower(header)) != headers.end();
}

std::string HTTPResponse::getValue(const std::string& key) {
    std::string target = TrimAndLower(key);
    return (headers.find(target) != headers.end()) ? headers.find(target)->second : std::string();
}

ParseType HTTPResponse::getParseType() {
    std::string value = getValue("content-type");
    MIME mime;
    if(value.empty()) {
        return ParseType::NONE;
    }
    
    if(value.find(';') != std::string::npos) {
        mime = MIME(value.substr(0, value.find(';')));
    } else if(value.find(' ') != std::string::npos) {
        mime = MIME(value.substr(0, value.find(' ')));
    } else {
        mime = MIME(value);
    }

    if(mime == MIME_TEXT_HTML || mime == MIME_TEXT_XML) {
        return ParseType::XML;
    } else if(mime == MIME_APP_JSON) {
        return ParseType::JSON;
    } else {
        return ParseType::XML;
    }
}

void HTTPResponse::addHeader(const std::string& str) {
    if(str.find(':') == std::string::npos) {
        fprintf(stderr,"HTTP Response error");
        return;
    }
    addHeader(str.substr(0,str.find(":")), str.substr(str.find(":") + 1));
}

void HTTPResponse::addHeader(const std::string& key, const std::string& value) {
    headers.insert(std::pair<std::string, std::string>(TrimAndLower(key), leftTrim(value)));
}

// struct ParseData
ParseData::ParseData() : depth(0), index(0) {}

ParseData::ParseData(const std::string& Text, int Place, int Depth, int Index) : place(Place), depth(Depth), index(Index), text(Text) {}

bool ParseData::empty() {
    return depth == 0;
}


// class HTMLParser

HTMLParser::HTMLParser() : mDocXML(std::make_unique<xmlDocument>()), mDocJSON(std::make_unique<rapidjson::Document>()) {}

HTMLParser::HTMLParser(std::string* data) : mDocXML(std::make_unique<xmlDocument>()), mDocJSON(std::make_unique<rapidjson::Document>()) {
    set(data);
}

HTMLParser::~HTMLParser() {}

std::vector<std::vector<ParseData>> HTMLParser::parseData(const std::vector<std::string>& target) {
    // target은 각각의 placeholder에 대한 target path를 나타냄
    std::vector<std::vector<ParseData>> ret;
    switch (mType)
    {
    case ParseType::XML:
    {
        for(int i = 0; i < (int) target.size(); ++i) {
            ret.push_back(parseXML(target[i], i));
        }
    }
    break;
    case ParseType::JSON :
    {
        for(int i = 0; i < (int) target.size(); ++i) {
            ret.push_back(parseJSON(target[i], i));
        }
    }
    break;
    default:
    
    break;
    }

    return ret;
}

void HTMLParser::set(std::string* data, const ParserOptions& parserOpts) {
    mData = data;
    mOptions = parserOpts;
    extractHeader(*mData);
    encodingData(mData);

    if(mOptions.defaultParseType.empty()) {
        mType = mResponse.getParseType();
    } else {
        std::string type = TrimAndLower(mOptions.defaultParseType);
        if(type == "json") {
            mType = ParseType::JSON;
        } else if(type == "xml" || type == "html") {
            mType = ParseType::XML;
        } else {
            mType = ParseType::XML;
        }
    }

    if(!mOptions.getOriginal && mType == ParseType::XML) {
        HTMLPreprocessing(*mData);
        HTMLCorrectError(*mData);
    }
    parse(mData->c_str());
}

bool HTMLParser::success() const {
    switch(mType) {
    case ParseType::XML : {
        xmlNode tnode = lastNode();
        HTMLTag rnode = lastNodeTag();
        bool attribute_check = true;
        if(tnode.first_attribute()) {
            std::vector<std::string> rattrs;
            std::string::iterator iter_begin = rnode.attribute.begin();
            std::string::iterator iter_end;
            std::string temp;
            bool isValue = false;

            auto iter_t = tnode.attributes_begin();
            for(auto it = rnode.attribute.begin(); it != rnode.attribute.end(); ++it) {
                if(!isValue && *it == '=') {
                    iter_end = it;
                    temp = std::string(iter_begin, iter_end);
                    removeSpace(temp);
                    if(temp != iter_t->name()) {
                        attribute_check = false;
                        break;
                    }
                    iter_begin = it;
                } else if(*it == '"' || *it == '\'') {
                    if(!isValue) {
                        iter_begin = it + 1;
                    } else {
                        iter_end = it;
                        temp = std::string(iter_begin, iter_end);
                        if(temp != iter_t->value()) {
                            attribute_check = false;
                            break;
                        }
                        iter_begin = it + 1;
                        ++iter_t;
                    }
                    isValue = !isValue;
                }
            }
        }
        return (tnode.name() == rnode.tag) && attribute_check;
    }
    break;
    case ParseType::JSON : {
        return !mDocJSON->HasParseError();
    }

    default:
        return false;
    break;
    }
    
}

void HTMLParser::HTMLPreprocessing(std::string& str) {
    // HTML 전처리 함수
    bool isTag = false; // Tag영역에 해당할 경우 true
    bool isClosingTag = false; // SelfClosingTag 여부
    bool isEscape = false; // 내용을 삭제할 Tag 여부
    bool isSingle = false; // 단일 Tag 중 삭제할 Tag 여부
    bool isAttribute = false; // Attribute에 해당할 경우 true
    bool isAttributeSkip = false; // "" 내용 스킵
    bool isAttributeHasValue = false; // Tag에 = 기호가 있을 시 true 
    std::string::iterator iter_erase_begin;
    std::string::iterator iter_erase_end;

    // 각 글자에 대해 처리
    for(auto it = str.begin(); it != str.end(); ++it) {
        if(isTag) {
            if(*it == '"') { 
                isAttributeSkip = !isAttributeSkip;
            }
            if(isAttributeSkip) { continue; }
        }
        if(isEscape){ // 내용 전체를 삭제할 Tag에 해당할 경우(script, style 등)
            if(*it != '<') { continue; }
            if(*(it + 1) != '/') { continue; }
            
            bool match = false;

            for(auto&& escape_tag : ESCAPE_TAGS) {
                if(matchString(it + 2, str.end(), escape_tag)) {
                    match = true;
                    break;
                }
            }
            if(!match) { continue; }
            
            for(iter_erase_end = it; iter_erase_end != str.end(); ++iter_erase_end) {
                if(*iter_erase_end == '>') {
                    break;
                }
            }
            rightEndSpace(iter_erase_end); // 공백 영역 추가
            it = str.erase(iter_erase_begin, iter_erase_end+1) - 1; // end에 + 1
            
            isTag = false;
            isEscape = false;
        } else if(isSingle) { // Single Tag 중 삭제할 Tag에 해당할 경우
            if(*it != '>') { continue; }

            if(*(iter_erase_begin + 2) == '-') {
                //<!--의 경우 -->로 끝나야 함
                if(*(it - 1) != '-') {
                    continue;
                } 
            }

            iter_erase_end = it;

            rightEndSpace(iter_erase_end); // 공백 영역 추가
            it = str.erase(iter_erase_begin, iter_erase_end+1) - 1;  // end에 + 1
            
            isTag = false;
            isSingle = false;
        } else if(isTag && *it == '>') { // Tag를 벗어날 때
            isTag = false;
            // Closing Tag이면 closing character 추가
            if(isClosingTag) {
                if(*(it - 1) != '/') {
                    it = str.insert(it,1,'/') + 1;
                } 
                isClosingTag = false;
            }

            // Tag Attribute 체크
            if(isAttribute && !isAttributeHasValue) {
                it = str.insert(it, 1, '=') + 1;
                it = str.insert(it, 2, '"') + 2;
            } else if(!isAttribute && isAttributeHasValue) {
                it = str.insert(it, 1, '"') + 1;
                isAttributeHasValue = false;
            }
            isAttribute = false;
            isAttributeSkip = false;
            isAttributeHasValue = false;
        } else if(isTag) {
            // Tag Attribute 체크

            if(*it == '=') {
                if(!isAttribute && *(it - 1) == ' ') {
                    it = str.insert(it, 3, 'z') + 3;
                }
                isAttributeHasValue = true;

                std::string::iterator iter_insert = it + 1;
                continueUntilChar(iter_insert);
                if(*(iter_insert) != '"' && *(iter_insert) != '\'') {
                    it = str.insert(iter_insert, 1, '"') + 1;
                    isAttribute = false;
                }
            }
            else if(isSpace(*it)) { // && *(it + 1) != '='
                if(isAttribute) {
                    std::string::iterator iter_erase = it;
                    continueUntilChar(iter_erase);
                    if(*(iter_erase) == '=') {
                        it = str.erase(it + 1, iter_erase) - 1;
                        continue;
                    }
                }
                if(isAttribute && !isAttributeHasValue) {
                    //Attribute이지만 값이 없는 경우 자동으로 값 설정
                    it = str.insert(it, 1, '=') + 1;
                    it = str.insert(it, 2, '"') + 2;
                    isAttribute = false;
                    isAttributeHasValue = false;
                }
                else if(!isAttribute && isAttributeHasValue) {
                    it = str.insert(it, 1, '"') + 1;
                    isAttributeHasValue = false;
                }
                if(isAlphabet(*(it + 1))) {
                    //알파벳 만나면 Attribute 설정
                    isAttribute = true;
                    isAttributeHasValue = false;
                }
            }
        } else if(!isTag && *it == '<') {
            if(!isAlphabet(*(it + 1)) && *(it + 1) != '!' && *(it + 1) != '/'){
                // 일반 텍스트 중 < 포함 여부 확인
                str.replace(it,it+1,"&lt");
            } else {
                isTag = true;
            }

            // Single Tag 여부 확인
            for(auto&& single_tag : SINGLE_ERASE_TAGS) {
                if(matchString(it + 1, str.end(), single_tag)) {
                    iter_erase_begin = it;
                    isSingle = true;
                    break;
                }
            }
            if(isSingle) { continue; }

            // Escape Tag 여부 확인
            for(auto&& escape_tag : ESCAPE_TAGS) {
                if(matchString(it + 1, str.end(), escape_tag)) {
                    iter_erase_begin = it;
                    isEscape = true;
                    break;
                }
            }
            if(isEscape) { continue; }

            // Closing Tag 여부 확인
            for(auto&& self_closing_tag : SELF_CLOSING_TAGS) {
                if(matchString(it + 1, str.end(), self_closing_tag)) {
                    isClosingTag = true;
                    break;
                }
            }
            if(isClosingTag) { continue; }
            
        } else if(!isTag && *it == '>') {
            str.replace(it,it+1,"&gt");
        }
    }
}

void HTMLParser::HTMLCorrectError(std::string& str) {
    std::vector<HTMLTag> stack;
    bool isTag = false;
    bool isTextNode = false;
    bool isAttributeSkip = false;
    bool hasAttribute = false;
    std::string::iterator iter_tag_begin;
    std::string::iterator iter_tag_end;
    int depth = 0;
    for(auto it = str.begin(); it != str.end(); ++it) {
        if(isTag) {
            if(*it == '"') { 
                isAttributeSkip = !isAttributeSkip;
            }
            if(isAttributeSkip) { continue; }
        }


        if(isTag && *it == '>') {
            bool isSelfClose = false;
            isTag = false;
            
            if(!hasAttribute) {
                iter_tag_end = it;
            }
            if(*(it-1) == '/') {
                isSelfClose = true;
            }

            std::string temp(iter_tag_begin, iter_tag_end);
            
            if(isTextNode) {
                //std::cout << "TextNode " << temp << std::endl;
            }
            if(temp.length() == 0) { continue; }
            if(temp[0] == '/') {
                //pop
                temp = temp.substr(1);
                
                bool valid = false;
                for(auto iter_stack = stack.rbegin(); iter_stack != stack.rend(); ++iter_stack) {
                    if( (*iter_stack).tag == temp ) {
                        valid = true;
                    }
                }

                if(!valid) {
                    it = str.erase(iter_tag_begin - 1,iter_tag_end + 1) - 1;
                    continue;
                }

                if(temp != stack.back().tag && depth > stack.back().depth) {
                    std::string insert_str = "</" + stack.back().tag + ">";
                    auto insert_it = iter_tag_begin - 1;
                    leftEndSpace(insert_it);
                    it = str.insert(insert_it, insert_str.begin(), insert_str.end());
                    //it += insert_str.length();
                }
                
                stack.pop_back();
                --depth;
            } else if(!isSelfClose) {
                //push
                //std::cout << depth << " : " << temp << std::endl;
                stack.push_back({temp, depth++});
            }
            isTextNode = false;
            isAttributeSkip = false;
            hasAttribute = false;
        } else if(isTag) {
            if(hasAttribute) { continue; }
            if(isSpace(*it)) { // *it == ' ' || *it == '\n'
                hasAttribute = true;
                iter_tag_end = it;
            }
        } else if(!isTag && *it == '<') {
            isTag = true;
            iter_tag_begin = it + 1;
            iter_tag_end  = it + 1;
        } else if(!isTag) {
            if(isTextNode) { continue; }
            if(isWord(*it)) {
                isTextNode = true;
            }
        }

    }

    while(!stack.empty()) {
        str.append("\r\n" + indent(stack.back().depth) + "</" + stack.back().tag + ">");
        stack.pop_back();
    }
}

const std::vector<std::string> HTMLParser::SELF_CLOSING_TAGS = {
    "area", "base", "br", "col ", "embed",
    "hr",  "link",//, "meta", //, "input"
    "param", "source", "track", "wbr"
};

const std::vector<std::string> HTMLParser::ESCAPE_TAGS = {
    "script", "style"
};

const std::vector<std::string> HTMLParser::SINGLE_ERASE_TAGS = {
    "!doctype", "!DOCTYPE", "!--", "input" ,"meta", "img"
};

HTMLParser::xmlNode HTMLParser::lastNode() const {
    xmlNode node = *mDocXML;
    while(node.last_child()) {
        node = node.last_child();
    }
    if(node.type() == 3) {
        node = node.parent();
    }
    return node;
}

HTMLTag HTMLParser::lastNodeTag() const {
    bool isTag = false;
    bool isAttributeSkip = false;
    std::string::const_reverse_iterator iter_tag_begin;
    std::string::const_reverse_iterator iter_tag_middle;
    std::string::const_reverse_iterator iter_tag_end;

    std::string tag;
    std::string attribute = "";
    int depth = -1;
    for(auto it = mData->crbegin(); it != mData->crend(); ++it) {
        if(isTag) {
            if(*it == '"') { 
                isAttributeSkip = !isAttributeSkip;
            }
            if(isAttributeSkip) { continue; }
        }
        if(*it == '>') {
            isTag = true;
            iter_tag_end = it;
            iter_tag_middle = it;
            if(*(it + 1) == '/') { 
                ++iter_tag_end;
                ++iter_tag_middle;
            }
            ++depth;
        } else if(*it == ' ') {
            iter_tag_middle = it;
        } else if(isTag && *it == '<') {
            isTag = false;
            isAttributeSkip = false;
            if(*(it - 1) == '/') { continue; }
            iter_tag_begin = it;

            tag = std::string(iter_tag_begin.base(), iter_tag_middle.base() - 1);
            if(iter_tag_middle != iter_tag_end) {
                attribute = std::string(iter_tag_middle.base(), iter_tag_end.base() - 1);
            }
            --depth;
            break;
        }
    }
    return { tag, depth, attribute };
}

void HTMLParser::extractHeader(std::string& str) {
    if(!mOptions.extractHeader) {
        return;
    }
    std::string line;
    if(std::string(str,0,4) != "HTTP") {
        return;
    }

    line = popStringLine(str);
    mResponse = HTTPResponse(line);

    while(!isEmpty(line = popStringLine(str))) {
        mResponse.addHeader(line);
    }
}

void HTMLParser::encodingData(std::string* str) {
    if(!mOptions.autoencoding) {
        return;
    }
    std::string ct = TrimAndUpper(mResponse.getValue("content-type"));
    size_t pos = ct.find("CHARSET=");
    if(pos == std::string::npos) {
        return;
    }
    std::string charset = ct.substr(pos + 8);
    if(!ChangeCharset(charset.c_str(), mOptions.defaultEncoding.c_str(), str)) {
        fprintf(stderr, "Invalid charset:%s\r\n", charset.c_str());
    }
}

void HTMLParser::parse(const char* data) {
    switch (mType)
    {
    case ParseType::XML : {
        mDocXML->load_string(data);
    }
    break;
    case ParseType::JSON :
        mDocJSON->Parse(data);
        break;
    default:
        mDocXML->load_string(data);
        break;
    }
    
}

std::vector<ParseData> HTMLParser::parseJSON(const std::string& target, int place, int index) {
    std::vector<ParseData> ret;
    if(target.empty()) {
        return ret;
    }
    int depth = std::count_if(target.begin(), target.end(), [](char c){ return (c == '/') ? true : false; });

    for(auto it = target.begin(); it != target.end(); ++it) {
        if(*it == '/' && *(it+1) == '*') {
            std::string targetPrefix(target.begin(), it);
            rapidjson::Pointer p(targetPrefix);
            if(!p.IsValid()) {
                fprintf(stderr, "Invalid target string\r\n");
                return ret;
            }
            rapidjson::Value* val = p.Get(*mDocJSON);
            if(val == nullptr) {
                fprintf(stderr, "Value does not exist\r\n");
                return ret;
            }
            if(!val->IsArray()) {
                fprintf(stderr, "Asterisk(*) part must be array type.\r\n");
                return ret;
            }
            for (rapidjson::SizeType i = 0; i < val->Size(); i++) {
                std::string targetSuffix(it, target.end());
                targetSuffix.replace(1,1,std::to_string(i));
                std::vector<ParseData> temp = parseJSON(targetPrefix + targetSuffix, place, i);
                ret.insert(ret.end(), temp.begin(), temp.end());
            }
            return ret;
        }
    }

    rapidjson::Pointer p(target);
    if(!p.IsValid()) {
        fprintf(stderr, "Invalid target string");
        return ret;
    }
    rapidjson::Value* val = p.Get(*mDocJSON);
    if(val == nullptr) {
        fprintf(stderr, "Value does not exist\r\n");
        return ret;
    }

    if(val->IsString()) {
        ret.push_back(ParseData(val->GetString(), place, depth, index));
    } else if(val->IsInt()) {
        ret.push_back(ParseData(std::to_string(val->GetInt()), place, depth, index));
    } else if(val->IsArray()) {
        for(auto& el : val->GetArray()) {
            if(el.IsString()) {
                ret.push_back(ParseData(el.GetString(), place, depth, index));
            } else if(el.IsInt()) {
                ret.push_back(ParseData(std::to_string(el.GetInt()), place, depth, index));
            }  else {
                fprintf(stderr, "Invalid array element type\r\n");
            }
        } 
    } else {
        fprintf(stderr, "Unknown Json type\r\n");
    }
    return ret;
}

std::vector<ParseData> HTMLParser::parseXML(const std::string& target, int place, int index) {
    std::vector<ParseData> ret;
    if(target.empty()) {
        return ret;
    }
    int depth = std::count_if(target.begin(), target.end(), [](char c){ return (c == '/') ? true : false; });

    for(auto it = target.begin(); it != target.end(); ++it) {
        if(*it == '/' && *(it+1) == '*') {
            try {
                std::string targetPrefix(target.begin(), it);   
                pugi::xpath_node select = mDocXML->select_node(targetPrefix.c_str());
                int count = 0;
                for(auto iter_select = select.node().begin(); iter_select != select.node().end(); ++iter_select) {
                    std::string targetSuffix(it, target.end());
                    std::string replaceString = iter_select->name() + std::string("[") + std::to_string(count+1) + "]";
                    targetSuffix.replace(1, 1, replaceString);
                    std::vector<ParseData> temp = parseXML(targetPrefix + targetSuffix, place, count);
                    ret.insert(ret.end(), temp.begin(), temp.end());
                    count++;
                }
            } catch(const pugi::xpath_exception& e) {
                fprintf(stderr, "Select Failed. : %s", e.what());
            }
            return ret;
        }
    }

    try {
        pugi::xpath_node select = mDocXML->select_node(target.c_str());
        ret.push_back(ParseData(select.node().child_value(), place, depth, index));
    } catch(const pugi::xpath_exception& e) {
        fprintf(stderr, "Select Failed. : %s", e.what());
    }
    return ret;
}

/*
std::vector<std::vector<ParseData>> HTMLParser::parseGrouping(const std::vector<std::vector<ParseData>>& data) {
    std::vector<std::vector<ParseData>> ret;
    std::vector<std::pair<std::vector<Crawler::ParseData>::const_iterator, std::vector<Crawler::ParseData>::const_iterator>> iters_pairs;

    for (auto it = data.begin(); it != data.end(); ++it) {
        ret.push_back(std::vector<ParseData>());
        iters_pairs.push_back(std::make_pair<std::vector<Crawler::ParseData>::const_iterator, std::vector<Crawler::ParseData>::const_iterator>(it->begin(), it->end()));
    }

    int currentIndex = 0;
    int maxDepth = -1;
    while (true)
    {
        std::vector<std::string> temp;
        bool valid = false;
        for (size_t i = 0; i < iters_pairs.size(); ++i) {
            auto& placepair = iters_pairs[i];
            while (true)
            {
                if(placepair.first != placepair.second) {
                    maxDepth = std::max(placepair.first->depth, maxDepth);
                    if (placepair.first->index == currentIndex) {
                        ret[i].push_back(*placepair.first);
                        //std::cout << placepair.first->text << std::endl;
                        ++placepair.first;
                        if(placepair.first == placepair.second) {
                            break;
                        }
                    } else {
                        break;
                    }
                } else {
                    if((placepair.first-1)->depth < maxDepth) {
                        ret[i].push_back(*(placepair.first-1));
                        //std::cout << "prev :" << (placepair.first - 1)->text << std::endl;
                    }
                    break;
                }
            }
            if(placepair.first != placepair.second) {
                valid |= true;
            }
        }

        if (!valid) {
            break;
        }
        //std::cout << "------" << std::endl;
        ++currentIndex;
    }
    return ret;
}
*/

}
/*
@backup(2022.10.25.)
void HTMLParser::HTMLPreprocessing(std::string& str) {
    // HTML 전처리 함수
    bool isTag = false; // Tag영역에 해당할 경우 true
    bool isClosingTag = false; // SelfClosingTag 여부
    bool isEscape = false; // 내용을 삭제할 Tag 여부
    bool isSingle = false; // 단일 Tag 중 삭제할 Tag 여부
    bool isAttribute = false; // A        //std::cout << mDocXML->first_child().name() << std::endl;ttribute에 해당할 경우 true
    bool isAttributeSkip = false; // "" 내용 스킵
    bool isAttributeHasValue = false; // Tag에 = 기호가 있을 시 true 
    std::string::iterator iter_erase_begin;
    std::string::iterator iter_erase_end;

    // 각 글자에 대해 처리
    for(auto it = str.begin(); it != str.end(); ++it) {
        if(isTag) {
            if(*it == '"') { 
                isAttributeSkip = !isAttributeSkip;
            }
            if(isAttributeSkip) { continue; }
        }
        if(isEscape){ // 내용 전체를 삭제할 Tag에 해당할 경우(script, style 등)
            if(*it != '<') { continue; }
            if(*(it + 1) != '/') { continue; }
            
            bool match = false;

            for(auto&& escape_tag : ESCAPE_TAGS) {
                if(matchString(it + 2, str.end(), escape_tag)) {
                    match = true;
                    break;
                }
            }
            if(!match) { continue; }
            
            for(iter_erase_end = it; iter_erase_end != str.end(); ++iter_erase_end) {
                if(*iter_erase_end == '>') {
                    break;
                }
            }
            rightEndSpace(iter_erase_end); // 공백 영역 추가
            it = str.erase(iter_erase_begin, iter_erase_end+1) - 1; // end에 + 1
            
            isTag = false;
            isEscape = false;
        } else if(isSingle) { // Single Tag 중 삭제할 Tag에 해당할 경우
            if(*it != '>') { continue; }

            if(*(iter_erase_begin + 2) == '-') {
                //<!--의 경우 -->로 끝나야 함
                if(*(it - 1) != '-') {
                    continue;
                } 
            }

            iter_erase_end = it;

            rightEndSpace(iter_erase_end); // 공백 영역 추가
            it = str.erase(iter_erase_begin, iter_erase_end+1) - 1;  // end에 + 1
            
            isTag = false;
            isSingle = false;
        } else if(isTag && *it == '>') { // Tag를 벗어날 때
            isTag = false;
            // Closing Tag이면 closing character 추가
            if(isClosingTag) {
                if(*(it - 1) != '/') {
                    it = str.insert(it,1,'/') + 1;
                } 
                isClosingTag = false;
            }

            // Tag Attribute 체크
            if(isAttribute == true && !isAttributeHasValue) {
                it = str.insert(it, 1, '=') + 1;
                it = str.insert(it, 2, '"') + 2;
            }
            isAttribute = false;
            isAttributeSkip = false;
        } else if(isTag) {
            // Tag Attribute 체크

            if(*it == '=' || *(it + 1) == '=') {
                isAttributeHasValue = true;
                isAttribute = false;
            }
            else if(*it == ' ') {
                if(isAttribute == true && !isAttributeHasValue) {
                    it = str.insert(it, 1, '=') + 1;
                    it = str.insert(it, 2, '"') + 2;
                    isAttribute = false;
                }
                if(isAlphabet(*(it + 1))) {
                    isAttribute = true;
                    isAttributeHasValue = false;
                }
            }
        } else if(!isTag && *it == '<') {
            if(!isAlphabet(*(it + 1)) && *(it + 1) != '!' && *(it + 1) != '/'){
                // 일반 텍스트 중 < 포함 여부 확인
                str.replace(it,it+1,"&lt");
            } else {
                isTag = true;
            }

            // Single Tag 여부 확인
            for(auto&& single_tag : SINGLE_ERASE_TAGS) {
                if(matchString(it + 1, str.end(), single_tag)) {
                    iter_erase_begin = it;
                    isSingle = true;
                    break;
                }
            }
            if(isSingle) { continue; }

            // Escape Tag 여부 확인
            for(auto&& escape_tag : ESCAPE_TAGS) {
                if(matchString(it + 1, str.end(), escape_tag)) {
                    iter_erase_begin = it;
                    isEscape = true;
                    break;
                }
            }
            if(isEscape) { continue; }

            // Closing Tag 여부 확인
            for(auto&& self_closing_tag : SELF_CLOSING_TAGS) {
                if(matchString(it + 1, str.end(), self_closing_tag)) {
                    isClosingTag = true;
                    break;
                }
            }
            if(isClosingTag) { continue; }
            
        } else if(!isTag && *it == '>') {
            str.replace(it,it+1,"&gt");
        }
    }
}
*/