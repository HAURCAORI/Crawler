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

void HTMLParser::HTMLSelfClosing(std::string& str) {
    bool isTag = false;
    bool isClosingTag = false;
    bool isEscape = false;
    bool isSingle = false;
    std::string::iterator iter_escape_begin;
    std::string::iterator iter_escape_end;

    for(auto it = str.begin(); it != str.end(); ++it) {
        if(isEscape){
            if(*it != '<') { continue; }
            if(*(it + 1) != '/') { continue; }
            
            bool match = false;
            for(iter_escape_end = it; iter_escape_end != str.end(); ++iter_escape_end) {
                if(*iter_escape_end == '>') {
                    match = true;
                    break;
                }
            }
            if(match) {
                str.erase(iter_escape_begin, iter_escape_end+1);
                it = iter_escape_begin;
                isTag = false;
                isEscape = false;
            } else {
                std::cout << "?" << std::endl;
            }

        } else if(isSingle) {
            if(*it != '>') { continue; }
            iter_escape_end = it;
            str.erase(iter_escape_begin, iter_escape_end+1);
            it = iter_escape_begin;
            isTag = false;
            isEscape = false;
            isSingle = false;
        } else if(isTag && *it == '>') {
            isTag = false;
            // Closing Tag이면 closing character 추가
            if(isClosingTag) {
                if(*(it - 1) != '/') {
                    str.insert(it,1,'/');
                } 
                isClosingTag = false;
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
                    iter_escape_begin = it;
                    isEscape = true;
                    break;
                }
            }
            if(isEscape) { continue; }

            // doctype 여부 확인
            if(matchString(it + 1, str.end(), "!doctype")) {
                iter_escape_begin = it;
                isSingle = true;
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

const std::vector<std::string> HTMLParser::SELF_CLOSING_TAGS = {
    "area", "base", "br", "col", "embed",
    "hr", "img", "input", "link", "meta",
    "param", "source", "track", "wbr"
};

const std::vector<std::string> HTMLParser::ESCAPE_TAGS = {
    "script", "style"
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