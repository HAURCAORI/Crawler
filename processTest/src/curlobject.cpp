#include "curlobject.h"
#include <utility>
#include <cstring>

//#include <iostream>

namespace Crawler {
using CURLFlag = Flags::CURLFlag;
// CURLObject Declaration

CURLObject::CURLObject() : mHandle(curl_easy_init()) {
    mData = std::make_unique<std::string>();
    defaultOption();
}

CURLObject::CURLObject(const std::string& url) : mHandle(curl_easy_init()){
    mData = std::make_unique<std::string>();
    setURL(url);
    defaultOption();
}

CURLObject::CURLObject(CURLObject&& src) noexcept : CURLObject() {
    swap(*this, src);
    //setOption(CURLOPT_WRITEDATA, &mData);
    setOption(CURLOPT_PRIVATE, this);
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
    //setOption(CURLOPT_WRITEDATA, &mData);
    setOption(CURLOPT_PRIVATE, this);
    return *this;
}

CURLObject::operator void*() const {
    return mHandle;
}

CURLcode CURLObject::perform() {
    performValid();
    CURLcode ret = curl_easy_perform(mHandle);
    if(ret == CURLE_OK) { performSuccess(); }
    return ret;
}

void CURLObject::resetOption() noexcept {
    curl_easy_reset(mHandle);
    setDone();
}

void CURLObject::defaultOption() {
    
    setOption(CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_2TLS);
    if(HasFlags(mFlags, CURLFlag::valid)) {
        setOption(CURLOPT_URL, mUrl.c_str()); // URL 설정
    }

    setOption(CURLOPT_WRITEFUNCTION, CURLObject::write_callback);
    setOption(CURLOPT_WRITEDATA, mData.get());
    setOption(CURLOPT_PRIVATE, this);

    setOption(CURLOPT_ACCEPT_ENCODING, "");

    //setOption(CURLOPT_VERBOSE, 1L);
}

void CURLObject::setURL(const std::string& str) {
    mUrl = str;
    setOption(CURLOPT_URL, mUrl.c_str());
    FlagsOn(mFlags, CURLFlag::valid);
    setDone();
}

void CURLObject::setContentType(const MIME& type) {
    appendHeader(HTMLHeaderString.at(HTMLHeader::contentType) + ":" + type.get());
}

void CURLObject::appendHeader(const std::string& str) {
    mHeader = curl_slist_append(mHeader, str.c_str());
    if (mHeader != NULL) {
        setOption(CURLOPT_HTTPHEADER, mHeader);
    }
    setDone();
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

void CURLObject::setAdapterOption(AdapterOption option, std::any value) {
    if(!mAdapter) {
        setFail();
        throw CURLErrorAdapter("Adapter should be initialized.");
    }
    if(value.type() == typeid(std::remove_reference_t<const char*>)) {
        value = std::string(std::any_cast<const char*>(value));
    }
    try {
        mAdapter->setOption(option, value);
        setDone();
    } catch(const CURLErrorAdapterOption& e) {
        fprintf(stderr,"%s\r\n", e.what());
        setFail();
    }
}

void CURLObject::setAdapterTarget(const std::vector<std::string>& target) {
    if(!mAdapter) {
        setFail();
        throw CURLErrorAdapter("Adapter should be initialized.");
    }
    mAdapter->setTarget(target);
    setDone();
}

void CURLObject::setCallback(std::packaged_task<void(bool)>&& func) {
    mCallback = std::move(func);
}

void CURLObject::callback(bool success) {
    if(mCallback.valid()) {
        mCallback(success);
    }
}

size_t CURLObject::write_callback(char* data, size_t size, size_t nmemb, void* userdata) {
    size_t realsize = size * nmemb;
    std::string* mem = reinterpret_cast<std::string*> (userdata);
    std::string temp(data, realsize);
    *mem += temp;
    return realsize;
}

void swap(CURLObject& first, CURLObject& second) noexcept {
    using std::swap;
    swap(first.mFlags, second.mFlags);
    swap(first.mUrl, second.mUrl);
    swap(first.mData, second.mData);
    swap(first.mHandle, second.mHandle);
    swap(first.mHeader, second.mHeader);
    swap(first.mAdapter, second.mAdapter);
    swap(first.mCallback, second.mCallback);
}

void CURLObject::setDone() {
    FlagsOn(mFlags, CURLFlag::good);
}

void CURLObject::setFail() {
    FlagsOff(mFlags, CURLFlag::good);
}

void CURLObject::performValid() {
    FlagsOff(mFlags, CURLFlag::success);
    if(!HasFlags(mFlags, CURLFlag::valid)) {
        throw CURLErrorURL("Empty URL.");
    }
    if(!mAdapter) {
        setAdapter<IOAdapter>();
    }
    if(!HasFlags(mFlags, CURLFlag::good)) {
        throw CURLError("Setting error");
    }
}

void CURLObject::performSuccess() {
    try {
        mAdapter->out();
        FlagsOn(mFlags, CURLFlag::success);
        callback(true);
    } catch(CURLErrorAdapterOut& e) {
        printf("%s\r\n",e.what());
        FlagsOff(mFlags, CURLFlag::success);
        callback(false);
    } catch(CURLErrorAdapter& e) {
        printf("%s\r\n",e.what());
        FlagsOff(mFlags, CURLFlag::success);
        callback(false);
    }
    
}

// CURLMultiObject declaration

CURLMultiObject::CURLMultiObject() : mHandle(curl_multi_init()) {}

CURLMultiObject::CURLMultiObject(CURLMultiObject&& src) noexcept : CURLMultiObject() {
    swap(*this, src);
}

CURLMultiObject::~CURLMultiObject() noexcept {
    if(mHandle) {
        curl_multi_cleanup(mHandle);
    }
}

CURLMultiObject& CURLMultiObject::operator=(CURLMultiObject&& rhs) noexcept {
    CURLMultiObject temp(std::move(rhs));
    swap(*this, temp);
    return *this;
}

void CURLMultiObject::addHandle(CURLObject&& obj) noexcept {
    try {
        obj.performValid();
        mContainer.emplace_back(std::move(obj));
        CURLMcode ret = curl_multi_add_handle(mHandle, mContainer.back().getHandle());
        if(ret != CURLM_OK) {
            mContainer.pop_back();
        }
    } catch(CURLErrorURL& e) {
        printf("%s\r\n",e.what());
    }
    // 실패 시 동작 구현size_t header_callback(char *buffer, size_t size, size_t nitems, void *userdata);
}

void CURLMultiObject::perform() {
    isInterrupt = false;
    int isRunning = true;
    int msgs_left = 0;
    while(isRunning && !isInterrupt) {
        int numfds;
        curl_multi_wait(mHandle, NULL, 0, time_out, &numfds);
        curl_multi_perform(mHandle, &isRunning);

        CURLMsg *m = NULL;
        while((m = curl_multi_info_read(mHandle, &msgs_left))) {
            
            if(m->msg == CURLMSG_DONE) {
                
                CURL *handle = m->easy_handle;
                
                CURLObject* obj;
                curl_easy_getinfo(handle, CURLINFO_PRIVATE, &obj);

                obj->performSuccess();
                curl_multi_remove_handle(mHandle, handle);
            }
        }
    }
}

void CURLMultiObject::interrupt() { isInterrupt = true; }
void CURLMultiObject::setTimeOut(size_t time) { time_out = time; }

void swap(CURLMultiObject& first, CURLMultiObject& second) noexcept {
    using std::swap;
}


// CURLMultiObject Global Variable
bool CURLMultiObject::isInterrupt = false;
size_t CURLMultiObject::time_out = 1000;

}