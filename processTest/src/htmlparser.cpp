#include "htmlparser.h"

#include <iostream>



namespace Crawler {

HTMLParser::HTMLParser() {}

HTMLParser::HTMLParser(const std::string* xml) {
    parse(xml->c_str());
}

HTMLParser::~HTMLParser() {}

void HTMLParser::parse(const char* xml) {
    doc.load_string(xml);
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
        if(isEscape){ // 내용 전체를 삭제할 Tag에 해당할 경우(script, style 등)
            if(*it != '<') { continue; }
            if(*(it + 1) != '/') { continue; }
            
            bool match = false;
            for(iter_erase_end = it; iter_erase_end != str.end(); ++iter_erase_end) {
                if(*iter_erase_end == '>') {
                    match = true;
                    break;
                }
            }
            if(match) {
                endSpace(iter_erase_end); // 공백 영역 추가
                it = str.erase(iter_erase_begin, iter_erase_end + 1) - 1;

                isTag = false;
                isEscape = false;
            }
        } else if(isSingle) { // Single Tag 중 삭제할 Tag에 해당할 경우
            if(*it != '>') { continue; }
            iter_erase_end = it;

            endSpace(iter_erase_end); // 공백 영역 추가
            it = str.erase(iter_erase_begin, iter_erase_end + 1) - 1;
            
            isTag = false;
            isSingle = false;
        } else if(isTag && *it == '>') { // Tag를 벗어날 때
            isTag = false;
            // Closing Tag이면 closing character 추가
            if(isClosingTag) {
                if(*(it - 1) != '/') {
                    it = str.insert(it,1,'/');
                } 
                isClosingTag = false;
            }

            // Tag Attribute 체크
            if(isAttribute == true && !isAttributeHasValue) {
                it = str.insert(it, 2, '"');
                it = str.insert(it, 1, '=');
            }
            isAttribute = false;
            isAttributeSkip = false;
        } else if(isTag) {
            // Tag Attribute 체크
            if(*it == '"') { 
                isAttributeSkip = !isAttributeSkip;
            }
            if(isAttributeSkip) { continue; }

            if(*it == '=') {
                isAttributeHasValue = true;
                isAttribute = false;
            }
            else if(*it == ' ') {
                if(isAttribute == true && !isAttributeHasValue) {
                    it = str.insert(it, 2, '"');
                    it = str.insert(it, 1, '=');
                    isAttribute = false;
                }
                if(isAlphabet(*(it + 1))) {
                    isAttribute = true;
                    isAttributeHasValue = false;
                }
            }
        } else if(!isTag && *it == '<') {
            isTag = true;
            // Closing Tag 여부 확인
            for(auto&& self_closing_tag : SELF_CLOSING_TAGS) {
                if(matchString(it + 1, str.end(), self_closing_tag)) {
                    isClosingTag = true;
                    break;
                }
            }
            if(isClosingTag) { continue; }

            // Escape Tag 여부 확인
            for(auto&& escape_tag : ESCAPE_TAGS) {
                if(matchString(it + 1, str.end(), escape_tag)) {
                    iter_erase_begin = it;
                    isEscape = true;
                    break;
                }
            }
            if(isEscape) { continue; }

            // Single Tag 여부 확인
            for(auto&& single_tag : SINGLE_ERASE_TAGS) {
                if(matchString(it + 1, str.end(), single_tag)) {
                    iter_erase_begin = it;
                    isSingle = true;
                    break;
                }
            }
        }
    }
}

bool HTMLParser::matchString(std::string::iterator iter_begin, std::string::iterator iter_end, const std::string& target) {
    bool match = true;
    auto it_target_tag = target.begin();
    for (auto it_tag = iter_begin; it_target_tag != target.end() && it_tag != iter_end; ++it_tag, ++it_target_tag) {
        if (*it_tag != *it_target_tag) {
            match = false;
            break;
        }
    }
    return match;
}

void HTMLParser::endSpace(std::string::iterator& it) {
    while(*(it+1) == ' ' || *(it+1) == '\n') { ++it; }
}

bool HTMLParser::isAlphabet(char ch) {
    return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z');
}

const std::vector<std::string> HTMLParser::SELF_CLOSING_TAGS = {
    "area", "base", "br", "col", "embed",
    "hr", "img", "link",//, "meta", //, "input"
    "param", "source", "track", "wbr"
};

const std::vector<std::string> HTMLParser::ESCAPE_TAGS = {
    "script", "style"
};

const std::vector<std::string> HTMLParser::SINGLE_ERASE_TAGS = {
    "!doctype", "!--", "input" ,"meta"
};



}
/*
self closing tag
<area />
<base />
<br />
<col />
<embed />
<hr />
<img />
<input />
<link />
<meta />
<param />
<source />
<track />
<wbr />
*/