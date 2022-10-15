#pragma once
#include <vector>
#include <curl/curl.h>
#include <curltype.h>
#include <curlexceptions.h>


namespace Crawler {


class CURLObject {
public:
    // 연산자 정의
    CURLObject();
    CURLObject(const std::string& url);
    CURLObject(const CURLObject& src) = delete;
    CURLObject(CURLObject&& src) noexcept;
    virtual ~CURLObject() noexcept;
    CURLObject& operator=(const CURLObject& rhs) = delete;
    CURLObject& operator=(CURLObject&& rhs) noexcept;
    operator void*() const;

    // CURL 동작 설정
    template<typename E>
    void setOption(CURLoption option, E&& param) {
        curl_easy_setopt(mHandle, option, param);
    }
    CURLcode perform() const;
    void resetOption() noexcept; // option reset
    void defaultOption();

    // get, set
    void setURL(const std::string& str);
    void setContentType(const MIME& type);
    void appendHeader(const std::string& str); // html header add
    void appendHeader(const MIME& type);
    void appendHeader(HTMLHeader header, const std::string& arg);

    inline CURL* getHandle() { return mHandle; }
    const CURL* getHandle() const { return mHandle; }
    const std::string& getURL() const { return mUrl; }

    // event
    static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);

    //기타
    friend void swap(CURLObject& first, CURLObject& second) noexcept;
private:
    bool isURLSet = false;
    std::string mUrl;
    CURL* mHandle = nullptr;
    curl_slist* mHeader = nullptr;
};
 
class CURLMultiObject {
public:
    // 연산자 정의
    CURLMultiObject();
    CURLMultiObject(const CURLMultiObject& src) = delete;
    CURLMultiObject(CURLMultiObject&& src) noexcept;
    virtual ~CURLMultiObject() noexcept;
    CURLMultiObject& operator=(const CURLMultiObject& rhs) = delete;
    CURLMultiObject& operator=(CURLMultiObject&& rhs) noexcept;

    // CURL_MULTI 동작 설정
    void addHandle(CURLObject&& obj) noexcept;
    void perform() const;

    // get, set

    //기타
    friend void swap(CURLMultiObject& first, CURLMultiObject& second) noexcept;
private:
    bool isInterrupt = false;
    size_t time_out = 1000;
    CURLM* mHandle = nullptr;
    std::vector<CURLObject> mContainer;
};

}