#ifndef CURL_IO_ADAPTER_H
#define CURL_IO_ADAPTER_H
#include <any>
#include <map>
#include <vector>
#include <memory>

#define ADAPTER_OUT processing();
#define StringMap(opt) { #opt, opt }

namespace Crawler {

struct ParserOptions;

enum AdapterOption {
  ADAPTER_OPT_NONE = 0,
  ADAPTER_OPT_PATH,
  ADAPTER_OPT_GET_ORIGINAL,
  ADAPTER_OPT_FORMAT,
  ADAPTER_OPT_FILE_TRUNC,
  ADAPTER_OPT_PARSE_TYPE,
  ADAPTER_OPT_ARRAY_DELIMITER
};

static const std::map<std::string, AdapterOption> StringMapAdapterOption = {
    StringMap(ADAPTER_OPT_NONE),
    StringMap(ADAPTER_OPT_PATH),
    StringMap(ADAPTER_OPT_GET_ORIGINAL),
    StringMap(ADAPTER_OPT_FORMAT),
    StringMap(ADAPTER_OPT_FILE_TRUNC),
    StringMap(ADAPTER_OPT_PARSE_TYPE),
    StringMap(ADAPTER_OPT_ARRAY_DELIMITER)
};

class HTMLParser;
struct ParseData;

// 수정 시 Curlcrawler.cpp getAdapter, setAdapter 수정
enum class AdapterType {
    NONE,
    IO_ADAPTER,
    IO_ADAPTER_CONSOLE,
    IO_ADAPTER_FILE
};

class IOAdapter {
public:
    IOAdapter();
    IOAdapter(std::string* data);
    IOAdapter(const IOAdapter& src) = delete;
    IOAdapter(IOAdapter&& src) noexcept;
    virtual ~IOAdapter() noexcept;
    IOAdapter& operator=(const IOAdapter& rhs) = delete;
    IOAdapter& operator=(IOAdapter&& rhs) noexcept;

    void set(std::string* data);
    virtual void out();
    virtual void setOption(AdapterOption option, const std::any& value);
    virtual void setTarget(const std::vector<std::string>& target);

    friend void swap(IOAdapter& first, IOAdapter& second) noexcept;
protected:
    std::vector<std::string> processing();
    std::unique_ptr<HTMLParser> mParser;
    std::unique_ptr<ParserOptions> mParserOptions;
    std::string* mData = nullptr;

    std::vector<std::string> mTarget; // 값을 가져올 대상 지정
    std::string mFormat; // 출력 형식 지정, 공백 및 $0 ~ $9 없을 시 순서대로 출력
private:
    std::string formatting(const std::vector<ParseData>& data);
};

class IOAdapterConsole : public IOAdapter {
public:
    using IOAdapter::IOAdapter;

    virtual void out() override;
private:
    
};

class IOAdapterFile : public IOAdapter {
public:
    using IOAdapter::IOAdapter;
    
    virtual void out() override;
    virtual void setOption(AdapterOption option, const std::any& value) override;
private:
    void writeFile(const std::string& data);
    void writeFile(const std::vector<std::string>& data);
    std::string mPath;
    bool mTrunc = false;
};

}

#endif