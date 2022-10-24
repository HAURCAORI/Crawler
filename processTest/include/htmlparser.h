#pragma once
#include <vector>
#include "pugixml.hpp"

namespace Crawler {
struct HTMLTag {
    std::string tag;
    int depth;
    std::string attribute = "";
};

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

    xmlNode lastNode() const;
    HTMLTag lastNodeTag() const;

    static void HTMLPreprocessing(std::string& str);
    static void HTMLCorrectError(std::string& str);

    static const std::vector<std::string> SELF_CLOSING_TAGS;
    static const std::vector<std::string> ESCAPE_TAGS;
    static const std::vector<std::string> SINGLE_ERASE_TAGS;
private:
    const std::string* mXml;
    xmlDocument doc;
};
}
