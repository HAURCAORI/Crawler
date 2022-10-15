#include <curlobject.h>
#include <utility>

namespace Crawler {

CURLObject::CURLObject() : mHandle(curl_easy_init()) {
    
}

CURLObject::CURLObject(const std::string& url) : mUrl(url), mHandle(curl_easy_init()){
    setOption(CURLOPT_URL, mUrl.c_str());
}

CURLObject::CURLObject(CURLObject&& src) noexcept : CURLObject() {
    swap(*this, src);
}

CURLObject::~CURLObject() noexcept {
    if(mHandle) {
        curl_easy_cleanup(mHandle);
    }
    if(mHeader) {
        curl_slist_free_all(mHeader);
    }
}

CURLObject& CURLObject::operator=(CURLObject&& rhs) noexcept {
    CURLObject temp(std::move(rhs));
    swap(*this, temp);
    return *this;
}

CURLObject::operator void*() const {
    return mHandle;
}

CURLcode CURLObject::perform() const {
    if(!isURLSet) {
        throw CurlErrorURL("Empty URL.");
    }
    return curl_easy_perform(mHandle);
}

void CURLObject::resetOption() noexcept {
    curl_easy_reset(mHandle);
}

void CURLObject::setURL(const std::string& str) {
    isURLSet = true;
    mUrl = str;
    setOption(CURLOPT_URL, mUrl.c_str());
}

void CURLObject::setContentType(const MIME& type) {
    appendHeader(HTMLHeaderString.at(HTMLHeader::contentType) + ":" + type.get());
}

void CURLObject::appendHeader(const std::string& str) {
    printf("%s\r\n", str.c_str());
    mHeader = curl_slist_append(mHeader, str.c_str());
}

void CURLObject::appendHeader(const MIME& type) {
    setContentType(type);
}

void CURLObject::appendHeader(HTMLHeader header, const std::string& arg) {
    switch(header) {
        default :
            appendHeader(HTMLHeaderString.at(header) + ":" + arg);
        break;
    }
}

void swap(CURLObject& first, CURLObject& second) noexcept {
    using std::swap;
    swap(first.mUrl, second.mUrl);
    swap(first.mHandle, second.mHandle);
}

}