#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include <ctime>

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
   /* {"https://www.naver.com/"},
    {"https://news.naver.com/"},
    {"https://news.naver.com/main/ranking/popularDay.naver"},
    {"https://finance.naver.com/"},
    {"https://www.google.com/"},
    {"https://www.dcinside.com/"}
    */
    //{"https://securities.koreainvestment.com/tfcommon/jisu/jisuData.json"}
    {"https://data.krx.co.kr/comm/bldAttendant/getJsonData.cmd"}

};

class HTMLTest {
public:
    HTMLTest() {}

    void execute() {
        int count = 0;
        for(auto&& site : site_list) {
            std::cout << site << " => " << perform(site, count++) << std::endl;
        }
    }
    static std::string perform(std::string url, int id) {
        Crawler::CURLObject obj(url);
        if(!obj) { return "[obj error]"; }

        std::string path = "./Output/test";
        path += std::to_string(id);
        path += ".html";
        obj.setAdapter<Crawler::IOAdapterFile>();
        obj.setAdapterOption(Crawler::ADAPTER_OPT_PATH, path);
        obj.setAdapterOption(Crawler::ADAPTER_OPT_GET_ORIGINAL, true);
        
        obj.appendHeader("User-Agent: Mozilla/5.0");
        
        obj.appendHeader(Crawler::MIME_APP_URLENCODED);

        obj.setOption(CURLOPT_VERBOSE, 1L);
        obj.setOption(CURLOPT_FOLLOWLOCATION, 1L);
        obj.setOption(CURLOPT_MAXREDIRS, 10L);
        obj.setOption(CURLOPT_CONNECTTIMEOUT, 2L);
        obj.setOption(CURLOPT_UNRESTRICTED_AUTH, 1L);
        obj.setOption(CURLOPT_PROXYAUTH, CURLAUTH_ANY);
        obj.setOption(CURLOPT_EXPECT_100_TIMEOUT_MS, 0L);
        obj.setOption(CURLOPT_COOKIEFILE, "");
        obj.setOption(CURLOPT_POST, 1L);
        
        std::string data = "bld=dbms/MDC/MAIN/MDCMAIN00104&mktId=STK";
        //time += std::to_string(static_cast<long int>(std::time(nullptr)));
        obj.setOption(CURLOPT_POSTFIELDS, data.c_str());

        auto res = obj.perform();
        if(res != CURLE_OK) {
            return "[perfomr error]";
        }

        Crawler::CURLObject* memory;
        curl_easy_getinfo(obj, CURLINFO_PRIVATE, &memory);

        Crawler::HTMLParser parser(&memory->getData());
        if(!parser.success()) {
            writeFile(path,memory->getData());
            return "[parsing error]";
        }
        
        return "[success]";
    }
    

private:

};