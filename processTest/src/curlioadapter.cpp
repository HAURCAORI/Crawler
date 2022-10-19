#include <utility>
#include <iostream>
#include "curlioadapter.h"
#include "curlexceptions.h"

namespace Crawler {


IOAdapter::IOAdapter(IOAdapter&& src) noexcept : IOAdapter(std::move(src.mData)) {
    swap(*this, src);
}


IOAdapter::~IOAdapter() noexcept {

}

IOAdapter& IOAdapter::operator=(IOAdapter&& rhs) noexcept {
    IOAdapter temp(std::move(rhs));
    swap(*this, temp);
    return *this;
}

void IOAdapter::set(std::string* data) { mData = data; }

void IOAdapter::out() const {
    std::cout << "IOAdapter" << std::endl;
}

void IOAdapter::setOption(AdapterOption option, const std::any& value) {}

void swap(IOAdapter& first, IOAdapter& second) noexcept {
    using std::swap;
    swap(first.mData,second.mData);
}

void IOAdapterConsole::out() const {
    std::cout << *mData << std::endl;
}


void IOAdapterFile::out() const {
    std::cout << mPath << std::endl;
}


void IOAdapterFile::setOption(AdapterOption option, const std::any& value) {
    switch(option) {
        case AdapterOption::ADAPTER_OPT_PATH: {
            if(value.type() != typeid(std::remove_reference_t<std::string>)) {
                throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_PATH' should be std::string");
            }
            mPath = std::any_cast<std::string>(value);
        }
        break;
        default:
        break;
    }
    
}

}