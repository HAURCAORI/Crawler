#ifndef HTML_PARSER_H
#define HTML_PARSER_H

#include <vector>
#include <memory>
#include <map>

/*
// is_vector typetrait
template<typename T, typename _ = void>
struct is_vector : std::false_type {};

template<typename T>
struct is_vector<T, typename std::enable_if<std::is_same<T, std::vector<typename T::value_type, typename T::allocator_type>>::value>::type> : std::true_type {};

template<class T>
inline constexpr bool is_vector_v = is_vector<T>::value;
*/

// Forward Declaration(rapidjson)
namespace rapidjson {
template<typename CharType>
struct UTF8;

template <typename Encoding, typename Allocator>
class GenericValue;

template <typename Encoding, typename Allocator, typename StackAllocator>
class GenericDocument;

class CrtAllocator;

template <typename BaseAllocator>
class MemoryPoolAllocator;

typedef rapidjson::GenericDocument<rapidjson::UTF8<char>,rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>,rapidjson::CrtAllocator> Document;
typedef rapidjson::GenericValue<rapidjson::UTF8<char>,rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>> Value;
typedef rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> Allocation;
}

// Forward Declaration(pugixml)
namespace pugi {
    class xml_node;
    class xml_attribute;
    class xml_document;
}

namespace Crawler {

enum class ParseType {
    NONE,
    XML,
    JSON
};

struct HTMLTag {
    std::string tag;
    int depth;
    std::string attribute = "";
};

struct ParserOptions {
    std::string defaultParseType = "";
    std::string arrayDelimiter = ",";
    std::string nullValue = "null";
    bool getOriginal = false;
};

struct HTTPResponse {
    std::string protocol;
    std::pair<int, std::string> statusCode;
    std::map<std::string, std::string> headers;
    HTTPResponse() = default;
    HTTPResponse(const std::string& line); // 'HTTP/1.X 200 OK' 형태의 데이터를 받음

    bool findHeader(const std::string header);
    std::string getValue(const std::string& key);
    ParseType getParseType();
    void addHeader(const std::string& str);
    void addHeader(const std::string& key, const std::string& value);
    
};

struct ParseData {
    int place;
    int depth;
    int index;
    std::string text;
    ParseData();
    ParseData(const std::string& text, int Place, int Depth, int Index);
    bool empty();
};

class HTMLParser { 
public:
    using xmlNode = pugi::xml_node;
    using xmlAttribute = pugi::xml_attribute;
    using xmlDocument = pugi::xml_document;

    HTMLParser();
    HTMLParser(std::string* data);
    HTMLParser(const HTMLParser& src) = default;
    HTMLParser(HTMLParser&& src) = default;
    virtual ~HTMLParser() noexcept;
    HTMLParser& operator=(const HTMLParser& rhs) = default;
    HTMLParser& operator=(HTMLParser&& rhs) = default;

    
    //xmlDocument* getDocument() { return &mDocXML; }

    std::vector<std::vector<ParseData>> parseData(const std::vector<std::string>& target);

    void set(std::string* data, const ParserOptions& parserOpts = ParserOptions());
    bool success() const;

    static void HTMLPreprocessing(std::string& str);
    static void HTMLCorrectError(std::string& str);

    static const std::vector<std::string> SELF_CLOSING_TAGS;
    static const std::vector<std::string> ESCAPE_TAGS;
    static const std::vector<std::string> SINGLE_ERASE_TAGS;
private:
    xmlNode lastNode() const;
    HTMLTag lastNodeTag() const;
    void extractHeader(std::string& str);
    void parse(const char* data);
    std::vector<ParseData> parseJSON(const std::string& target, int place, int index = 0);
    std::vector<ParseData> parseXML(const std::string& target, int place, int index = 0);
    std::vector<std::vector<ParseData>> parseGrouping(const std::vector<std::vector<ParseData>>& data);

    HTTPResponse mResponse;
    std::string* mData;
    ParseType mType;
    ParserOptions mOptions;

    std::unique_ptr<xmlDocument> mDocXML;
    std::unique_ptr<rapidjson::Document> mDocJSON;
};
}

#endif