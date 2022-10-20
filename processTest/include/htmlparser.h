#pragma once
#include "pugixml.hpp"

namespace Crawler {
class HTMLParser {
public:
    using xmlNode = pugi::xml_node;
    using xmlDocument = pugi::xml_document;

    HTMLParser();
    HTMLParser(const char* xml);
    HTMLParser(const HTMLParser& src) = default;
    HTMLParser(HTMLParser&& src) = default;
    virtual ~HTMLParser() noexcept;
    HTMLParser& operator=(const HTMLParser& rhs) = default;
    HTMLParser& operator=(HTMLParser&& rhs) = default;

    void parse(const char* xml);
    xmlDocument* getDocument() { return &doc;}

private:
    xmlDocument doc;

};
}
/*
const XMLNode* Parent()
bool NoChildren()
const XMLNode* FirstChild()
const XMLElement* FirstChildElement(const char*)
const XMLNode* lastChild()
const XMLElement* LastChildElement(const char*)
const XMLNode* PreviousSibling()
const XMLElement* PreviousSiblingElement(const char*)
const XMLNode* NextSibling()
const XMLElement* NextSiblingElement(const char*)

*/