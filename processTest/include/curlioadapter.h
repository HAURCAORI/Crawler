#pragma once

namespace Crawler {

class IOAdapter {
public:
    IOAdapter();
    IOAdapter(const IOAdapter& src) = delete;
    IOAdapter(IOAdapter&& src) noexcept;
    virtual ~IOAdapter() noexcept;
    IOAdapter& operator=(const IOAdapter& rhs) = delete;
    IOAdapter& operator=(IOAdapter&& rhs) noexcept;

    virtual void out();
    const void* get() const { return mdata; };

    friend void swap(IOAdapter& first, IOAdapter& second) noexcept;
private:
    void* mdata = nullptr; 
};

class IOAdapterConsole : public IOAdapter {
public:
    IOAdapterConsole() = default;
private:
    
};

}