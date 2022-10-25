#include <utility>
#include <iostream>
#include <fstream>
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

void IOAdapter::out() {
    //std::cout << "IOAdapter" << std::endl;
}

void IOAdapter::setOption(AdapterOption option, const std::any& value) {
    switch (option)
    {
    case ADAPTER_OPT_GET_ORIGINAL: {
            if(value.type() != typeid(std::remove_reference_t<bool>)) {
                throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_GET_ORIGINAL' should be bool");
            }
            mGetOriginal = std::any_cast<bool>(value);
        }
        break;
    
    default:
        break;
    }
}

void swap(IOAdapter& first, IOAdapter& second) noexcept {
    using std::swap;
    swap(first.mData,second.mData);
}

void IOAdapterConsole::out() {
    std::cout << *mData << std::endl;
}


void IOAdapterFile::out() {
    std::cout << mPath << std::endl;
    writeFile();
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
        IOAdapter::setOption(option, value); // Chain of responsibility pattern
        break;
    }
    
}

void IOAdapterFile::writeFile() {
    std::ofstream outFile(mPath, std::ios_base::trunc);
    if(!outFile.good()) {
        throw CURLErrorAdapterOut("Error while opening file.");
    }
    outFile << *mData;
}

}