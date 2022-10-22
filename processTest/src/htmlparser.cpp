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
    
}
}