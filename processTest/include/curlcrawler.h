#ifndef CURL_CRAWLER_H
#define CURL_CRAWLER_H
#include "curlobject.h"
#include "curlthreadpool.h"
#include <vector>
#include <memory>
#include <map>


#include <future>

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
typedef rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator> Allocation;
}

namespace Scheduler {
class Schedule;
class EventScheduler;
}

namespace Crawler {

// Enum
enum class Method { NONE, GET, POST };
static const std::map<Method, std::string> strMethod = {{ Method::GET, "GET" }, { Method::POST, "POST" }};
enum class OutputType { NONE, String, Value, Bool };
static const std::map<OutputType, std::string> strOutputType = {{ OutputType::String, "String" }, { OutputType::Value, "Value" }, { OutputType::Bool, "Bool" }};
enum class Adapter { NONE, File, Console, SQL };
static const std::map<Adapter, std::string> strAdapter = {{ Adapter::File, "File" }, { Adapter::Console, "Console" }, { Adapter::SQL, "SQL" }};
enum class CrawlingScheduleType { NONE, Once, Interval, Daily, Weekly, Monthly };
static const std::map<CrawlingScheduleType, std::string> strScheduleType = {{ CrawlingScheduleType::Once, "Once" }, { CrawlingScheduleType::Interval, "Interval" }, { CrawlingScheduleType::Daily, "Daily" }, { CrawlingScheduleType::Weekly, "Weekly" }, { CrawlingScheduleType::Monthly, "Monthly" }};


typedef std::vector<std::string> Headers;
typedef std::vector<std::pair<std::string, std::string>> Options;
typedef std::pair<std::string, std::string> Option;
typedef std::vector<std::vector<std::string>> Placeholders;
typedef std::vector<std::string> Placeholder;

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
    std::string target;  // via function
    std::vector<std::string> placeholders;
    OutputType type;
    Adapter adapter;
    Options options;
    Output() : type(OutputType::String), adapter(Adapter::Console) {}
    Output(const std::string& dir, Adapter adap = Adapter::Console, OutputType outputType = OutputType::String) : target(dir), type(outputType), adapter(adap) {}
    void addPlaceholder(const std::string& value) { placeholders.push_back(value); }
    void addOption(const std::pair<std::string, std::string>& opt) { options.push_back(opt); }
};

// Schedule Struct
struct Schedule {
    CrawlingScheduleType type;
    std::string start;
    std::string expired;
    std::string interval;
    Schedule() : type(CrawlingScheduleType::Once) {}
    Schedule(CrawlingScheduleType schedule) : type(schedule) {}
    Schedule(CrawlingScheduleType schedule, const std::string& startTime, const std::string& expiredTime, const std::string& intervalTime)
                : type(schedule), start(startTime), expired(expiredTime), interval(intervalTime) {}
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
private:
    rapidjson::Value& mCrawlingNode;
    rapidjson::Allocation& alloc;
    
    std::unique_ptr<Scheduler::Schedule> mSchedule;

    void enqueueObject(const std::string& url);
    void success(bool result);
    void initialize();
    std::future<void> mFuture;
public:
    CrawlingObject(rapidjson::Value& value, rapidjson::Allocation& allocation);
    CrawlingObject(const CrawlingObject& src) = delete;
    CrawlingObject(CrawlingObject&& src) = default;
    virtual ~CrawlingObject() noexcept;
    CrawlingObject& operator=(const CrawlingObject& src) = delete;
    CrawlingObject& operator=(CrawlingObject&& src) = default;

    // Process
    void execute();
    void init();

    Scheduler::Schedule* getSchedule() const;

    // ID
    std::string getID() const;

    // URI
    std::string getURL() const;
    Method getMethod() const;
    std::vector<std::string> getHeaders() const;
    Options getURIOptions() const;
    std::string getParameters() const;
    Placeholders getURLPlaceholders() const;
    void setURL(const std::string& url);
    void setMethod(Method method);
    void setHeaders(const Headers& headers);
    void appendHeader(const std::string& header);
    void setURIOptions(const Options& options);
    void appendURIOption(const Option& option);
    void setParameters(const std::string& parameters);
    void setURLPlaceholders(const Placeholders& placeholders);

    // OUTPUT
    std::string getTarget() const;
    OutputType getOutputType() const;
    AdapterType getAdapter() const;
    Options getOutputOptions() const;
    Placeholders getOutputPlaceholders() const;
    void setTarget(const std::string& target);
    void setOutputType(OutputType outputtype);
    void setAdapter(AdapterType adapter);
    void setOutputOptions(const Options& options);
    void appendOutputOption(const Option& option);
    void setOutputPlaceholders(const Placeholders& placeholders);

    // SCHEDULE
    CrawlingScheduleType getScheduleType() const;
    std::string getScheduleStart() const;
    std::string getScheduleExpired() const;
    std::string getScheduleInterval() const;
    //std::string getScheduleValue() const;
    void setScheduleType(CrawlingScheduleType scheduletype);
    void setScheduleStart(const std::string& time);
    void setScheduleExpired(const std::string& time);
    void setScheduleInterval(const std::string& time);
    //void setScheduleValue(const std::string& value);

    // INFO
    bool isValid() const;
    bool isSuccess() const;
    int64_t getTimestamp() const;
    int getPerformCount() const;
    std::string getDetails() const;

    bool operator==(const CrawlingObject& rhs);
};

/*
    CrawlingList.json ?????? key ?????? ??? ?????? ??????
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

    void add(CrawlingObject&& obj);
    bool addList(const std::string& id, const URI& uri, Output output, Schedule schedule);
    bool addList(const std::string& id, const std::string& url, const std::string& target, Adapter adapter = Adapter::Console);
    void eraseList(); // ?????? ?????? x
    
    //temp
    int temp() { return mObj.size(); }

    size_t count();

    CrawlingObject& at(size_t index);
    CrawlingObject& at(const std::string& id);
    CrawlingObject& operator[](size_t index);
    CrawlingObject& operator[](const std::string& id);


    // Valid flag ???????????? Valid Method ????????????

    void setSaveChange(bool value);
private:
    rapidjson::Value createListNode(const std::string& id, const URI& uri, const Output& output, const Schedule& schedule); // Json List ??????
    rapidjson::Value createInfoNode(); // Json List ??????
    void validCheckAll();
    void validCheck(rapidjson::Value& node); // ?????? ?????? ??????(Info ????????? ?????? ??????), valid flag??? false??? ??????
    void initObject();
    void initSchedule();
    bool saveListFile() noexcept;
    bool loadListFile();
    bool idDuplicated(const std::string& id);


    bool isLoaded = false;
    bool isSaveChanges = true;
    int mCount = 0;
    std::unique_ptr<rapidjson::Document> mDoc;
    std::vector<CrawlingObject> mObj;
    std::string mListFilePath;
    static const std::string DEFAULT_PATH;
    static const std::string DEFAULT_JSON;
    static const char* ROOT_NODE;
    
    std::unique_ptr<Scheduler::EventScheduler> mScheduler;
};

}

#endif