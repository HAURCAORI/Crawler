#ifndef CURL_CRAWLER_H
#define CURL_CRAWLER_H
#include "curlobject.h"
#include <vector>
#include <memory>
#include <map>

// Forward Declaration
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
}

namespace Crawler {

// Enum
enum class Method { GET, POST };
static const std::map<Method, std::string> strMethod = {{ Method::GET, "GET" }, { Method::POST, "POST" }};
enum class OutputType { String, Value, Bool };
static const std::map<OutputType, std::string> strOutputType = {{ OutputType::String, "String" }, { OutputType::Value, "Value" }, { OutputType::Bool, "Bool" }};
enum class Adapter { File, Console, SQL };
static const std::map<Adapter, std::string> strAdapter = {{ Adapter::File, "File" }, { Adapter::Console, "Console" }, { Adapter::SQL, "SQL" }};
enum class ScheduleType { Once, Time, Interval, Weekly, Daily };
static const std::map<ScheduleType, std::string> strScheduleType = {{ ScheduleType::Once, "Once" }, { ScheduleType::Time, "Time" }, { ScheduleType::Interval, "Interval" }, { ScheduleType::Weekly, "Weekly" }, { ScheduleType::Daily, "Daily" }};


typedef std::vector<std::string> Headers;

// URI Struct
struct URI {
    std::string url;
    Method method;
    Headers headers; // via function
    std::string parameters;
    std::vector<std::string> placeholders; // via function
    URI() : method(Method::GET) {}
    URI(const std::string& URL) : url(URL), method(Method::GET){}
    URI(const std::string& URL, Method type) : url(URL), method(type){}
    URI(const std::string& URL, const std::string& param, Method type = Method::GET) : url(URL), method(type), parameters(param){}
    void addHeader(const std::string& header) { headers.push_back(header); }
    void addPlaceholder(const std::string& value) { placeholders.push_back(value); }
};

// Output Struct
struct Output {
    std::string target;
    std::vector<std::string> placeholders;
    OutputType type;
    Adapter adapter;
    std::vector<std::pair<std::string, std::string>> options;
    Output() : type(OutputType::String), adapter(Adapter::Console) {}
    Output(const std::string& dir, Adapter adap = Adapter::Console, OutputType outputType = OutputType::String) : target(dir), type(outputType), adapter(adap) {}
    void addPlaceholder(const std::string& value) { placeholders.push_back(value); }
    void addOption(const std::pair<std::string, std::string>& opt) { options.push_back(opt); }
};

// Schedule Struct
struct Schedule {
    ScheduleType type;
    std::string value;
    Schedule() : type(ScheduleType::Once) {}
    Schedule(ScheduleType schedule) : type(schedule) {}
    Schedule(ScheduleType schedule, const std::string& val) : type(schedule), value(val) {}
};

// Info Struct
struct Info {
    bool valid;
    bool success;
    int64_t timestamp;
    int performCount;
    std::string details;
};

class CrawlingObject {
public:
    CrawlingObject(rapidjson::Value& value);
    CrawlingObject(const CrawlingObject& src) = default;
    CrawlingObject(CrawlingObject&& src) = default;
    virtual ~CrawlingObject() noexcept;
    CrawlingObject& operator=(const CrawlingObject& src) = default;
    CrawlingObject& operator=(CrawlingObject&& SRC) = default;

    std::string getURL() const;
    
private:
    rapidjson::Value& mValue;
};

/*
    CrawlingList.json 파일 key 추가 시 수정 항목
    1. createListNode()
    2. createInfoNode()
    3. validCheck()
*/

class CURLCrawler {
public:
    CURLCrawler();
    CURLCrawler(const CURLCrawler& src) = delete;
    CURLCrawler(CURLCrawler&& src) = delete;
    virtual ~CURLCrawler() noexcept;
    CURLCrawler& operator=(const CURLCrawler& src) = delete;
    CURLCrawler& operator=(CURLCrawler&& src) = delete;

    bool loadList(const std::string& path = DEFAULT_PATH);
    static bool createListFile(const std::string& path = DEFAULT_PATH, bool trunc = false);

    void addList(const std::string& id, const URI& uri, Output output, Schedule schedule);
    void addList(const std::string& id, const std::string& url, const std::string& target, Adapter adapter = Adapter::Console);
    void eraseList();

    CrawlingObject at(size_t index);
    CrawlingObject at(const std::string& id);
    CrawlingObject operator[](size_t index);
    CrawlingObject operator[](const std::string& id);
    
    

private:
    rapidjson::Value createListNode(const std::string& id, const URI& uri, const Output& output, const Schedule& schedule); // Json List 생성
    rapidjson::Value createInfoNode(); // Json List 생성
    void validCheckAll();
    void validCheck(rapidjson::Value& node);
    bool saveListFile() noexcept;
    bool loadListFile();

    bool isLoaded = false;
    int mCount = 0;
    std::unique_ptr<rapidjson::Document> mDoc;
    std::string mListFilePath;
    static const std::string DEFAULT_PATH;
    static const std::string DEFAULT_JSON;
    static const char* ROOT_NODE;
};

}

#endif