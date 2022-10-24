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

struct Sites {
    std::string site;
    std::string last_tag;
};

static const std::vector<Sites> site_list = {
    {"https://www.naver.com/", "div"}
};

class HTMLTest {
public:
    HTMLTest();


void HTMLPreprocessingTest(std::string str);

private:

};