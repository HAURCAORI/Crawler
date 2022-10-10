#pragma once
#include <curl/curl.h>
#include <curlexceptions.h>

namespace Crawler {
class CURLObject {
public:
    CURLObject();
    CURLObject(std::string url);
    CURLObject(const CURLObject& src) = delete;
    CURLObject(CURLObject&& src) noexcept;
    virtual ~CURLObject() noexcept;
    CURLObject& operator=(const CURLObject& rhs) = delete;
    CURLObject& operator=(CURLObject&& rhs) noexcept;
    
    operator void*() const;

    template<typename E>
    void setopt(CURLoption option, E&& param) {
        curl_easy_setopt(mHandle, option, param);
    }
    CURLcode perform();

    inline CURL* getHandle() { return mHandle; }
    const CURL* getHandle() const { return mHandle; }

    friend void swap(CURLObject& first, CURLObject& second) noexcept;
private:
    std::string mUrl;
    CURL* mHandle = nullptr;
};
 


}