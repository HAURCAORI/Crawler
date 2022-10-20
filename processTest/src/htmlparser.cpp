#include "htmlparser.h"

namespace Crawler {

HTMLParser::HTMLParser() {}

HTMLParser::HTMLParser(const char* xml) {
    parse(xml);
}

HTMLParser::~HTMLParser() {}

void HTMLParser::parse(const char* xml) {
    doc.Parse(xml);
}
}