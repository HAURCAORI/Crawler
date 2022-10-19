#pragma once
#include <any>

namespace Crawler {
enum AdapterOption {
  ADAPTER_OPT_NONE = 0,
  ADAPTER_OPT_PATH
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
    virtual void out() const;
    virtual void setOption(AdapterOption option, const std::any& value);
    
    friend void swap(IOAdapter& first, IOAdapter& second) noexcept;
protected:
    std::string* mData = nullptr;
};

class IOAdapterConsole : public IOAdapter {
public:
    using IOAdapter::IOAdapter;

    virtual void out() const override;

private:
    
};

class IOAdapterFile : public IOAdapter {
public:
    using IOAdapter::IOAdapter;
    
    virtual void out() const override;
    virtual void setOption(AdapterOption option, const std::any& value);
private:
    std::string mPath;
};

}