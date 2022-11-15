#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include <iostream>
#include <ctime>

#include "curlobject.h"
#include "curlcrawler.h"
/*
static std::string readFile(std::string path) {
    std::ifstream inFile(path);
    if(!inFile.good()) {
        return "";
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}
*/

static bool writeFile(std::string path, const std::string& data) {
    std::ofstream outFile(path, std::ios_base::trunc);
    if(!outFile.good()) {
        return false;
    }
    outFile << data;
    return true;
}


static const std::vector<std::string> site_list = {
    {"https://new.land.naver.com/api/articles/complex/113302?realEstateType=APT%3AJGC%3AABYG&tradeType=&tag=%3A%3A%3A%3A%3A%3A%3A%3A&rentPriceMin=0&rentPriceMax=900000000&priceMin=0&priceMax=900000000&areaMin=0&areaMax=900000000&oldBuildYears&recentlyBuildYears&minHouseHoldCount&maxHouseHoldCount&showArticle=false&sameAddressGroup=false&minMaintenanceCost&maxMaintenanceCost&priceType=RETAIL&directions=&page=1&complexNo=113302&buildingNos=&areaNos=&type=list&order=rank"}

    //{"https://www.naver.com/"},
    //{"https://news.naver.com/"},
    //{"https://news.naver.com/main/ranking/popularDay.naver"},
    //{"https://finance.naver.com/"},
    //{"https://www.google.com/"},
    //{"https://www.dcinside.com/"},
    
    //{"https://securities.koreainvestment.com/tfcommon/jisu/jisuData.json"}
    //{"https://data.krx.co.kr/comm/bldAttendant/getJsonData.cmd"}

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
        
        obj.appendHeader("Host: new.land.naver.com");
        obj.appendHeader("Referer: https://new.land.naver.com/complexes?ms=37.4122794,126.6246398,17&a=APT:JGC:ABYG&e=RETAIL");
        obj.appendHeader("User-Agent: Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/107.0.0.0 Safari/537.36");
        obj.appendHeader("authorization: Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpZCI6IlJFQUxFU1RBVEUiLCJpYXQiOjE2Njc0Nzg5ODEsImV4cCI6MTY2NzQ4OTc4MX0.RLr1SlstN_-sFeeci5cgv-sn24qIESCTd5ZpgDJRT_0");
        
        //obj.appendHeader(Crawler::MIME_APP_URLENCODED);

        obj.setOption(CURLOPT_VERBOSE, 1L);


        //obj.setOption(CURLOPT_POST, 1L);
        std::string data = "realEstateType=APT%3AJGC%3AABYG&tradeType=&tag=%3A%3A%3A%3A%3A%3A%3A%3A&rentPriceMin=0&rentPriceMax=900000000&priceMin=0&priceMax=900000000&areaMin=0&areaMax=900000000&oldBuildYears&recentlyBuildYears&minHouseHoldCount&maxHouseHoldCount&showArticle=false&sameAddressGroup=false&minMaintenanceCost&maxMaintenanceCost&priceType=RETAIL&directions=&page=1&complexNo=113302&buildingNos=&areaNos=&type=list&order=rank";
        //time += std::to_string(static_cast<long int>(std::time(nullptr)));
        //obj.setOption(CURLOPT_POSTFIELDS, data.c_str());

        auto res = obj.perform();
        if(res != CURLE_OK) {
            return "[perfomr error]";
        }

        Crawler::CURLObject* memory;
        curl_easy_getinfo(obj, CURLINFO_PRIVATE, &memory);

        Crawler::HTMLParser parser(memory->getData());
        if(!parser.success()) {
            writeFile(path,*memory->getData());
            return "[parsing error]";
        }
        
        return "[success]";
    }
    

private:

};

class CrawlingObjectTest {
public:
    CrawlingObjectTest();

    static void print(Crawler::CrawlingObject temp)
    {   
        using namespace Crawler;
        std::cout << "[URL]" << std::endl
                  << temp.getURL() << std::endl;
        if (temp.getMethod() == Method::POST || temp.getMethod() == Method::GET)
        {
            std::cout << "[Method] OK." << std::endl;
        }
        std::cout << "[Headers]" << std::endl;
        for (auto t : temp.getHeaders())
        {
            std::cout << t << std::endl;
        }
        std::cout << "[Parameters]" << std::endl
                  << temp.getParameters() << std::endl;
        std::cout << "[Placeholders]" << std::endl;
        for (auto t : temp.getURLPlaceholders())
        {
            //std::cout << t << std::endl;
        }
    }

};