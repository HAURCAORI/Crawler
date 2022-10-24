#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include "curlobject.h"

static std::string readFile(std::string path) {
    std::ifstream inFile(path);
    if(!inFile.good()) {
        return "";
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}

static bool writeFile(std::string path, const std::string& data) {
    std::ofstream outFile(path, std::ios_base::trunc);
    if(!outFile.good()) {
        return false;
    }
    outFile << data;
    return true;
}


static const std::vector<std::string> site_list = {
    {"https://www.naver.com/"}
};

class HTMLTest {
public:
    HTMLTest() {}

    void execute() {
        for(auto&& site : site_list) {
            std::cout << site << " => " << perform(site) << std::endl;
        }
    }
    static std::string perform(std::string url) {
        Crawler::CURLObject obj(url);
        if(!obj) { return "obj error"; }
        
        auto res = obj.perform();
        if(res != CURLE_OK) {
            return "perfomr error";
        }
/*
        Crawler::CURLObject* memory;
        curl_easy_getinfo(obj, CURLINFO_PRIVATE, &memory);

        Crawler::HTMLParser parser(&memory->getData());
        if(!parser.success()) {
            return "parser error";
        }
        */
         return "success";
    }
    

private:

};