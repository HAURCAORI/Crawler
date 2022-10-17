#include <utility>
#include <iostream>
#include "curlioadapter.h"

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

void IOAdapter::out() const {
    std::cout << "IOAdapter" << std::endl;
}

void swap(IOAdapter& first, IOAdapter& second) noexcept {
    using std::swap;
    swap(first.mData,second.mData);
}

void IOAdapterConsole::out() const {
    std::cout << "IOAdapterConsole" << std::endl;
}


}