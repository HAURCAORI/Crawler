#ifndef CURL_IO_ADAPTER_H
#define CURL_IO_ADAPTER_H
#include <any>
#include <memory>

#define ADAPTER_OUT processing();

namespace Crawler {

enum AdapterOption {
  ADAPTER_OPT_NONE = 0,
  ADAPTER_OPT_PATH,
  ADAPTER_OPT_GET_ORIGINAL
};

class HTMLParser;

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
    
    bool isGetOriginal() { return mGetOriginal; }

    friend void swap(IOAdapter& first, IOAdapter& second) noexcept;
protected:
    void processing();
    std::unique_ptr<HTMLParser> mParser;
    std::string* mData = nullptr;
    bool mGetOriginal = false;
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
    void writeFile();
    std::string mPath;
};

}

#endif