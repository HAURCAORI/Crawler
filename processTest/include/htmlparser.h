#pragma once
#include "pugixml.hpp"

namespace Crawler {
class HTMLParser {
public:
    using xmlNode = pugi::xml_node;
    using xmlAttribute = pugi::xml_attribute;
    using xmlDocument = pugi::xml_document;

    HTMLParser();
    HTMLParser(const std::string* xml);
    HTMLParser(const HTMLParser& src) = default;
    HTMLParser(HTMLParser&& src) = default;
    virtual ~HTMLParser() noexcept;
    HTMLParser& operator=(const HTMLParser& rhs) = default;
    HTMLParser& operator=(HTMLParser&& rhs) = default;

    void parse(const char* xml);
    xmlDocument* getDocument() { return &doc; }
        
    static void HTMLSelfClosing(std::string& str);

private:
    xmlDocument doc;

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