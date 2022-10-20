#pragma once
#include "tinyxml2.h"

namespace Crawler {
class HTMLParser {
public:
    using xmlElement = tinyxml2::XMLElement;
    using xmlDocument = tinyxml2::XMLDocument;

    HTMLParser();
    HTMLParser(const char* xml);
    HTMLParser(const HTMLParser& src) = default;
    HTMLParser(HTMLParser&& src) = default;
    virtual ~HTMLParser() noexcept;
    HTMLParser& operator=(const HTMLParser& rhs) = default;
    HTMLParser& operator=(HTMLParser&& rhs) = default;

    void parse(const char* xml);

    static xmlElement* getFirstChildElement(xmlElement* element, const char* value = (const char*) 0) {
        return element->FirstChildElement(value);
    }

    static xmlElement* getLastChildElement(xmlElement* element, const char* value = (const char*) 0) {
        return element->LastChildElement(value);
    }

    static xmlElement* getPreviousSiblingElement(xmlElement* element, const char* value = (const char*) 0) {
        return element->PreviousSiblingElement(value);
    }

    static xmlElement* getNextSiblingElement(xmlElement* element, const char* value = (const char*) 0) {
        return element->NextSiblingElement(value);
    }

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