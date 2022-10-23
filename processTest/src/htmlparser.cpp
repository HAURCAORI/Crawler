#include "htmlparser.h"
#include <stack>

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
            endSpace(iter_erase_end); // 공백 영역 추가
            it = str.erase(iter_erase_begin, iter_erase_end + 1) - 1;
            
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

            endSpace(iter_erase_end); // 공백 영역 추가
            it = str.erase(iter_erase_begin, iter_erase_end + 1) - 1;
            
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

void HTMLParser::HTMLCorrectError(std::string& str) {
    std::stack<HTMLTag> stack;
    bool isTag = false;
    bool isTagNameSet = false;
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
            if(temp.at(0) == '/') {
                //pop

                stack.pop();
                --depth;
            } else if(!isSelfClose) {
                //push
                std::cout << depth << " : " << temp << std::endl;
                stack.push({temp, depth++});
            }


            isAttributeSkip = false;
            hasAttribute = false;
        } else if(isTag) {
            if(hasAttribute) { continue; }
            if(*it == ' ' || *it == '\n') {
                hasAttribute = true;
                iter_tag_end = it;
            }
        } else if(!isTag && *it == '<') {
            isTag = true;
            iter_tag_begin = it + 1;
            isTagNameSet = false;
        }
        
        /*
        if(isTag && *it == '>') {
            isTag = false;
            if(!isTagNameSet) {
                if(*iter_tag_begin == '/') {
                    std::string temp(iter_tag_begin + 1, it);
                    if(stack.top() == temp) {
                        stack.pop();
                    } else {
                        std::string closing = "</" + stack.top() + ">";
                        it = str.insert(it+1, closing.begin(), closing.end()) + 1;
                        std::cout << temp << "(invalid)" << std::endl;
                    }
                } else {
                    std::string temp(iter_tag_begin, it);
                    stack.push(std::move(temp));
                }
                isTagNameSet = true;
            } else {
                if(*(it - 1) == '/') {
                    stack.pop();
                }
            }
        } else if(isTag) {
            if(*it == ' ' || *it == '\n') {
                if(!isTagNameSet) {
                    std::string temp(iter_tag_begin, it);
                    stack.push(std::move(temp));
                    isTagNameSet = true;
                }
            }
        } else if(!isTag && *it == '<') {
            isTag = true;
            iter_tag_begin = it + 1;
            isTagNameSet = false;
        }
        */

    }

    while(!stack.empty()) {
        str.append("\r\n" + indent(stack.top().depth) + "</" + stack.top().tag + ">");
        stack.pop();
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

std::string HTMLParser::indent(int depth) {
    return std::string(std::max(depth-1,0), '\t');
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
    "!doctype", "!--", "input" ,"meta", "img"
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