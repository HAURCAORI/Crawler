#ifndef CURL_EXCEPTIONS_H
#define CURL_EXCEPTIONS_H

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

class CURLErrorURL : public CURLError {
public:
    CURLErrorURL(const std::string& message) : CURLError(message) {}
};

class CURLErrorAdapter : public CURLError {
public:
    CURLErrorAdapter(const std::string& message) : CURLError(message) {}
};

class CURLErrorAdapterOption : public CURLError {
public:
    CURLErrorAdapterOption(const std::string& message) : CURLError(message) {}
};

class CURLErrorAdapterOut : public CURLError {
public:
    CURLErrorAdapterOut(const std::string& message) : CURLError(message) {}
};

}

#endif