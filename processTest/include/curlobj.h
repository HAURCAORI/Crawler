#pragma once
#include <curl/curl.h>
#include <curlexceptions.h>

namespace Crawler {

struct MIME {
    std::string type;
    std::string subtype;
    MIME(const std::string& type, const std::string& subtype);
    std::string get();
};

static const MIME MIME_TEXT_PLAIN = MIME("text","plain");
static const MIME MIME_TEXT_CSS = MIME("text","css");
static const MIME MIME_TEXT_CSV = MIME("text","csv");
static const MIME MIME_TEXT_HTML = MIME("text","html");
static const MIME MIME_TEXT_XML = MIME("text","xml");
static const MIME MIME_MULTI_FORM = MIME("multipart","form-data");
static const MIME MIME_IMAGE_PNG = MIME("image","png");
static const MIME MIME_IMAGE_JPEG = MIME("image","jpeg");
static const MIME MIME_AUDIO_MPEG = MIME("audio","mpeg");
static const MIME MIME_APP_ZIP = MIME("application","zip");
static const MIME MIME_APP_XML = MIME("application","xml");
static const MIME MIME_APP_URLENCODED = MIME("application","x-www-form-urlencoded");
static const MIME MIME_APP_PDF = MIME("application","pdf");
static const MIME MIME_APP_JSON = MIME("application","json");
static const MIME MIME_APP_JAVASCRIPT = MIME("application","javascript");


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