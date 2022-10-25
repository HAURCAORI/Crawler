#pragma once
#include <any>
#include "htmlparser.h"

namespace Crawler {
enum AdapterOption {
  ADAPTER_OPT_NONE = 0,
  ADAPTER_OPT_PATH,
  ADAPTER_OPT_GET_ORIGINAL
};


class IOAdapter {
public:
    IOAdapter() = default;
    IOAdapter(std::string* data) : mData(data) {}
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