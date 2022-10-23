#pragma once
#include <vector>
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
        
    static void HTMLPreprocessing(std::string& str);
    static void HTMLCorrectError(std::string& str);

    static const std::vector<std::string> SELF_CLOSING_TAGS;
    static const std::vector<std::string> ESCAPE_TAGS;
    static const std::vector<std::string> SINGLE_ERASE_TAGS;
private:
    xmlDocument doc;

    static bool matchString(std::string::iterator iter_begin, std::string::iterator iter_end, const std::string& target);
    static void rigntEndSpace(std::string::iterator& it);
    static void leftEndSpace(std::string::iterator& it);
    static bool isAlphabet(char ch);
    static std::string indent(int depth);
    static bool isWord(char ch);
    struct HTMLTag {
        std::string tag;
        int depth;
    };
};
}
