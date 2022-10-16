#include <utility>
#include "curlioadapter.h"

namespace Crawler {

IOAdapter::IOAdapter() {}

IOAdapter::IOAdapter(IOAdapter&& src) noexcept : IOAdapter() {
    swap(*this, src);
}

IOAdapter::~IOAdapter() noexcept {

}

IOAdapter& IOAdapter::operator=(IOAdapter&& rhs) noexcept {
    IOAdapter temp(std::move(rhs));
    swap(*this, temp);
    return *this;
}


void swap(IOAdapter& first, IOAdapter& second) noexcept {
    using std::swap;
}


}