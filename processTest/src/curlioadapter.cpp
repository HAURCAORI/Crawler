#include <utility>
#include <iostream>
#include <fstream>

#include <algorithm>

// time format
#include <stdio.h>
#include <time.h>

#include "curlioadapter.h"
#include "curlexceptions.h"
#include "htmlparser.h"
#include "stringextension.h"

using namespace std::string_literals;

namespace Crawler {

IOAdapter::IOAdapter(IOAdapter&& src) noexcept : IOAdapter(std::move(src.mData)) {
    swap(*this, src);
}

IOAdapter::IOAdapter() : mParser(std::make_unique<HTMLParser>()), mParserOptions(std::make_unique<ParserOptions>()) {

}

IOAdapter::IOAdapter(std::string* data) : mParser(std::make_unique<HTMLParser>()), mParserOptions(std::make_unique<ParserOptions>()), mData(data) {

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
    try {
        processing();
    } catch(const CURLErrorAdapterOut& e) {
        fprintf(stderr, "%s\r\n", e.what());
    }
}

void IOAdapter::setOption(AdapterOption option, const std::any& value) {
    switch (option)
    {
    case ADAPTER_OPT_GET_ORIGINAL: {
        if(value.type() != typeid(std::remove_reference_t<bool>)) {
            throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_GET_ORIGINAL' should be bool");
        }
        mParserOptions->getOriginal = std::any_cast<bool>(value);
    }
    break;
    case ADAPTER_OPT_FORMAT: {
        if(value.type() != typeid(std::remove_reference_t<std::string>)) {
            throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_FORMAT' should be string");
        }
        mFormat = std::any_cast<std::string>(value);
    }
    break;
    case AdapterOption::ADAPTER_OPT_ARRAY_DELIMITER: {
        if(value.type() != typeid(std::remove_reference_t<std::string>)) {
            throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_ARRAY_DELIMITER' should be string");
        }
        mParserOptions->arrayDelimiter = std::any_cast<std::string>(value);
    }
    break;
    case AdapterOption::ADAPTER_OPT_EXTRACT_HEADER: {
        if(value.type() != typeid(std::remove_reference_t<bool>)) {
            throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_EXTRACT_HEADER' should be bool");
        }
        mParserOptions->extractHeader = std::any_cast<bool>(value);
    }
    break;
    case AdapterOption::ADAPTER_OPT_AUTO_ENCODING: {
        if(value.type() != typeid(std::remove_reference_t<bool>)) {
            throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_AUTO_ENCODING' should be bool");
        }
        mParserOptions->autoencoding = std::any_cast<bool>(value);
    }
    break;
    case AdapterOption::ADAPTER_OPT_DEFAULT_ENCODING: {
        if(value.type() != typeid(std::remove_reference_t<std::string>)) {
            throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_DEFAULT_ENCODING' should be string");
        }
        mParserOptions->defaultEncoding = std::any_cast<std::string>(value);
    }
    break;
    default:
        std::string optionString;
        for(auto it = StringMapAdapterOption.begin(); it != StringMapAdapterOption.end(); ++it){
            if(it->second == option) {
                optionString = it->first;
                break;
            }
        }
        throw CURLErrorAdapterOption("Undefined option:"s + optionString +"."s);
    break;
    }
}

void IOAdapter::setTarget(const std::vector<std::string>& target) {
    mTarget = target;
}

void swap(IOAdapter& first, IOAdapter& second) noexcept {
    using std::swap;
    swap(first.mData,second.mData);
}

std::vector<std::string> IOAdapter::processing() {
    std::vector<std::string> ret;
    if(!mData) {
        throw CURLErrorAdapterOut("Adapter data is null.");
    }
    mParser->set(mData, *mParserOptions);
    if(mParserOptions->getOriginal) {
        return ret;
    }
    
    if(!mParser->success()) {
        throw CURLErrorAdapterOut("Parser fails.");
    }
    std::vector<std::vector<ParseData>> data = mParser->parseData(mTarget);

/*
    for(auto& vec : data) {
        for(auto& el : vec) {
            std::cout << el.text << std::endl;
        }
    }
*/

    std::vector<std::pair<std::vector<Crawler::ParseData>::iterator, std::vector<Crawler::ParseData>::iterator>> iters_pairs;

    for (auto it = data.begin(); it != data.end(); ++it) {
        iters_pairs.push_back(std::make_pair<std::vector<Crawler::ParseData>::iterator, std::vector<Crawler::ParseData>::iterator>(it->begin(), it->end()));
    }

    int currentIndex = 0;
    //int maxDepth = -1;
    while (true) {
        std::vector<Crawler::ParseData> temp;
        bool valid = false;
        for (size_t i = 0; i < iters_pairs.size(); ++i) {
            auto& placepair = iters_pairs[i];
            while (true) {
                if(placepair.first != placepair.second) {
                    //maxDepth = std::max(placepair.first->depth, maxDepth);
                    if (placepair.first->index == currentIndex) {
                        temp.push_back(*placepair.first);
                        //std::cout << placepair.first->text << std::endl;
                        ++placepair.first;
                        if(placepair.first == placepair.second) {
                            break;
                        }
                    } else {
                        break;
                    }
                } else {
                    //if((placepair.first-1)->depth < maxDepth) {
                    if((placepair.first-1)->index == 0) {
                        temp.push_back(*(placepair.first-1));
                        //std::cout << "prev :" << (placepair.first - 1)->text << std::endl;
                    } else {
                        temp.push_back(Crawler::ParseData());
                        //std::cout << "prev :null" << std::endl;
                    }
                    break;
                }
            }
            if(placepair.first != placepair.second) {
                valid |= true;
            }
        }

        ret.push_back(formatting(temp));
        //std::cout << "-----" << std::endl;
        if (!valid) {
            break;
        }
        ++currentIndex;
    }

   return ret;
}

std::string IOAdapter::formatting(const std::vector<ParseData> &data){
    bool brace = false;
    std::string::iterator iter_start;
    std::string format = mFormat;
    if(format.empty()) {
        format = "$@";
    }
    for (auto it = format.begin(); it != format.end(); ++it) {
        if (*it == '$') {
            if (brace) { continue; }
            if (*(it + 1) == '@') {
                size_t pos = std::distance(format.begin(), it);
                std::string replaceString;
                for (auto iter_data = data.begin(); iter_data != data.end(); ++iter_data) {
                    stringAppendDelimiter(replaceString, iter_data->text, mParserOptions->arrayDelimiter);
                }

                format = format.replace(it, it + 2, replaceString);
                it = format.begin() + pos + replaceString.size() - 1;
            } else if (isdigit(*(it + 1))) {
                int index = (*(it + 1) - '0');
                size_t pos = std::distance(format.begin(), it);
                std::string replaceString;
                for (auto iter_data = data.begin(); iter_data != data.end(); ++iter_data) {
                    if (iter_data->place == index) {
                        stringAppendDelimiter(replaceString, iter_data->text, mParserOptions->arrayDelimiter);
                    }
                }
                if (replaceString.empty()) {
                    replaceString = mParserOptions->nullValue;
                }
                format = format.replace(it, it + 2, replaceString);
                it = format.begin() + pos + replaceString.size() - 1;
            } else if (*(it + 1) == '{') {
                brace = true;
                iter_start = it + 2;
            }
        } else if (brace && *it == '}') {
            // ????????? ?????? => strftime ????????? ??????
            std::string temp(iter_start, it);

            time_t rawtime;
            struct tm *timeinfo;
            char buffer[256];

            time(&rawtime);
            timeinfo = localtime(&rawtime);

            if (strftime(buffer, 256, temp.c_str(), timeinfo)) {
                std::string timeString(buffer);
                size_t pos = std::distance(format.begin(), iter_start - 2);
                format = format.replace(iter_start - 2, it + 1, timeString);
                it = format.begin() + pos + timeString.size() - 1;
            }
            brace = false;
        }
    }
    return format;
}

// Adaptor Console

void IOAdapterConsole::out() {
    try {
        processing();
        std::cout << *mData << std::endl;
    } catch(const CURLErrorAdapterOut& e) {
        fprintf(stderr, "%s\r\n", e.what());
    }
}


void IOAdapterFile::out() {
    try {
        auto ret = processing();
        if(mParserOptions->getOriginal) {
            writeFile(*mData);
        } else {
            writeFile(ret);
        }
    } catch(const CURLErrorAdapterOut& e) {
        fprintf(stderr, "%s\r\n", e.what());
    }
}


void IOAdapterFile::setOption(AdapterOption option, const std::any& value) {
    switch(option) {
        case AdapterOption::ADAPTER_OPT_PATH: {
            if(value.type() != typeid(std::remove_reference_t<std::string>)) {
                throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_PATH' should be std::string.");
            }
            mPath = std::any_cast<std::string>(value);
        }
        break;
        case AdapterOption::ADAPTER_OPT_FILE_TRUNC: {
            if(value.type() != typeid(std::remove_reference_t<bool>)) {
                throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_FILE_TRUNC' should be bool.");
            }
            mTrunc = std::any_cast<bool>(value);
        }
        break;
        case AdapterOption::ADAPTER_OPT_PARSE_TYPE: {
            if(value.type() != typeid(std::remove_reference_t<std::string>)) {
                throw CURLErrorAdapterOption("Value type of 'ADAPTER_OPT_PARSE_TYPE' should be std::string.");
            }
            mParserOptions->defaultParseType = std::any_cast<std::string>(value);
        }
        break;
        default:
        IOAdapter::setOption(option, value); // Chain of responsibility pattern
        break;
    }
    
}

void IOAdapterFile::writeFile(const std::string& data) {
    std::ofstream outFile(mPath, std::ios_base::trunc);
    if(!outFile.good()) {
        throw CURLErrorAdapterOut("Error while opening file.");
    }
    outFile << data;
}

void IOAdapterFile::writeFile(const std::vector<std::string>& data) {
    std::ofstream outFile(mPath, (mTrunc) ? std::ios_base::trunc : std::ios_base::app);
    if(!outFile.good()) {
        throw CURLErrorAdapterOut("Error while opening file.");
    }
    for(const auto& d : data) {
        outFile << d << std::endl;
    }
}

}