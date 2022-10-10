#pragma once
#include <exception>
#include <string>

namespace Crawler {

class CurlError : std::exception {
public:
    CurlError(const std::string& message) : mMessage(message) {}

    virtual const char* what() const noexcept override {
        return mMessage.c_str();
    }
protected:
    void setMessage(const std::string& message) { mMessage = message; }
private:
    std::string mMessage;
};

}