#include <utility>
#include <cstring>
#include "curlobject.h"


namespace Crawler {

// memory Declaration
memory::memory() {

}

memory::~memory() {
    if(mData != NULL) { free(mData); }
}

size_t memory::append(char* data, size_t size) {
    char *ptr = (char *)realloc(mData, mSize + size + 1);
    if (ptr == NULL) {
        return 0;
    }
    mData = ptr;
    memcpy(&(mData[mSize]), data, size);
    mSize += size;
    mData[mSize] = 0;
    return size;
}


// CURLObject Declaration

CURLObject::CURLObject() : mHandle(curl_easy_init()) {
    defaultOption();
}

CURLObject::CURLObject(const std::string& url) : mHandle(curl_easy_init()){
    setURL(url);
    defaultOption();
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

void CURLObject::defaultOption() {

    //mAdapter = std::make_unique<IOAdapterConsole>();
    if(isURLSet) {
        setOption(CURLOPT_URL, mUrl.c_str()); // URL 설정
    }

    setOption(CURLOPT_WRITEDATA, &mData);
    setOption(CURLOPT_WRITEFUNCTION, CURLObject::write_callback);
    setOption(CURLOPT_PRIVATE, this);

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

size_t CURLObject::write_callback(char* data, size_t size, size_t nmemb, void* userdata) {
    size_t realsize = size * nmemb;
    memory* mem = (memory*) (userdata);
    mem->append(data,realsize);
    return realsize;
}

void swap(CURLObject& first, CURLObject& second) noexcept {
    using std::swap;
    swap(first.mUrl, second.mUrl);
    swap(first.mHandle, second.mHandle);
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
    CURLMcode ret = curl_multi_add_handle(mHandle, obj.getHandle());
    if(ret == CURLM_OK) {
        mContainer.push_back(std::move(obj));
    }
    // 실패 시 동작 구현
}

void CURLMultiObject::perform() const {
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

                double time;
                curl_easy_getinfo(handle, CURLINFO_TOTAL_TIME, &time);
                printf("%f\r\n",time);

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