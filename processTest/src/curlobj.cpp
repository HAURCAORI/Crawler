#include <curlobj.h>
#include <utility>

namespace Crawler {

MIME::MIME(const std::string& type, const std::string& subtype) : type(type), subtype(subtype) {}
std::string MIME::get() { return type + "/" + subtype; }

CURLObject::CURLObject() : mHandle(curl_easy_init()) {
    
}

CURLObject::CURLObject(std::string url) : mUrl(url), mHandle(curl_easy_init()){
    setopt(CURLOPT_URL, mUrl.c_str());
}

CURLObject::CURLObject(CURLObject&& src) noexcept : CURLObject() {
    swap(*this, src);
}

CURLObject::~CURLObject() noexcept {
    if(mHandle) {
        curl_easy_cleanup(mHandle);
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

CURLcode CURLObject::perform() {
    return curl_easy_perform(mHandle);
}

void CURLObject::reset() noexcept {
    curl_easy_reset(mHandle);
}

void CURLObject::setURL(const std::string& str) {
    mUrl = str;
    setopt(CURLOPT_URL, mUrl.c_str());
}

void swap(CURLObject& first, CURLObject& second) noexcept {
    using std::swap;
    swap(first.mUrl, second.mUrl);
    swap(first.mHandle, second.mHandle);
}

}