#pragma once
#include <curl/curl.h>
#include <curltype.h>
#include <curlexceptions.h>


namespace Crawler {


class CURLObject {
public:
    // 연산자 정의
    CURLObject();
    CURLObject(std::string url);
    CURLObject(const CURLObject& src) = delete;
    CURLObject(CURLObject&& src) noexcept;
    virtual ~CURLObject() noexcept;
    CURLObject& operator=(const CURLObject& rhs) = delete;
    CURLObject& operator=(CURLObject&& rhs) noexcept;
    operator void*() const;

    // CURL 동작 설정
    template<typename E>
    void setopt(CURLoption option, E&& param) {
        curl_easy_setopt(mHandle, option, param);
    }
    CURLcode perform();
    void reset() noexcept;

    // get, set
    void setURL(const std::string& str);
    void appendHeader(const std::string& str);
    void appendHeader(int a, const std::string& arg);
    

    inline CURL* getHandle() { return mHandle; }
    const CURL* getHandle() const { return mHandle; }
    const std::string& getURL() const { return mUrl; }

    //기타
    friend void swap(CURLObject& first, CURLObject& second) noexcept;
private:
    std::string mUrl;
    CURL* mHandle = nullptr;
    curl_slist* mHeader = nullptr;
};
 


}