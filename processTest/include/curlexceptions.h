#pragma once
#include <exception>
#include <string>

namespace Crawler {

class CURLError : std::exception {
public:
    CURLError(const std::string& message) : mMessage(message) {}

    virtual const char* what() const noexcept override {
        return mMessage.c_str();
    }
protected:
    void setMessage(const std::string& message) { mMessage = message; }
private:
    std::string mMessage;
};

class CURLErrorURL : CURLError {
public:
    CURLErrorURL(const std::string& message) : CURLError(message) {}
};

class CURLErrorAdapter : CURLError {
public:
    CURLErrorAdapter(const std::string& message) : CURLError(message) {}
};

}