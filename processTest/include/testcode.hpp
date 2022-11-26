#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

#include <iostream>
#include <ctime>

#include "curlobject.h"
#include "curlcrawler.h"
#include "stringextension.h"

inline std::string readFile(std::string path) {
    std::ifstream inFile(path);
    if(!inFile.good()) {
        return "";
    }
    std::stringstream buffer;
    buffer << inFile.rdbuf();
    return buffer.str();
}


inline bool writeFile(std::string path, const std::string& data) {
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

class ParsingTest {
public:
    ParsingTest() {}

    void excute() {
        Crawler::HTMLParser mParser;
        std::string data = readFile("./Input/parse.json");
        std::string target = readFile("./Input/target.txt");
        std::vector<std::string> targets = split(target,"\n");
        Crawler::ParserOptions mOptions;
        mOptions.defaultParseType = "json";
        mParser.set(&data, mOptions);
        
        if(!mParser.success()) {
            throw Crawler::CURLErrorAdapterOut("Parser fails.");
        }
        
        std::vector<std::vector<Crawler::ParseData>> result = mParser.parseData(targets);
        processing(result);
        /*
        for(auto& r : result) {
            for(auto& pd : r) {
                std::cout << pd.place << "|" << pd.depth << "|" << pd.index << "|" << pd.text << std::endl;
            }
            std::cout << "-----" << std::endl;
        }
        */
        

    }

    std::string formatting(const std::vector<Crawler::ParseData> &data) {
        bool brace = false;
        std::string::iterator iter_start;
        std::string format = "$@ |$0 | $1 | $2 | $3";
        for(auto it = format.begin(); it != format.end(); ++it) {
            if(*it == '$') {
                if(brace) { continue; }
                if(*(it + 1) == '@') {
                    size_t pos = std::distance(format.begin(), it);
                    std::string replaceString;
                    for(auto iter_data = data.begin(); iter_data != data.end(); ++iter_data) {
                        stringAppendDelimiter(replaceString, iter_data->text, ",");
                    } 
                    
                    format = format.replace(it, it + 2, replaceString);
                    it = format.begin() + pos + replaceString.size() - 1;
                } else if(isdigit(*(it + 1))) {
                    int index = (*(it + 1) - '0');
                    size_t pos = std::distance(format.begin(), it);
                    std::string replaceString;
                    for(auto iter_data = data.begin(); iter_data != data.end(); ++iter_data) {
                        if(iter_data->place == index){
                            stringAppendDelimiter(replaceString, iter_data->text, ",");
                        }
                    } 
                    if(replaceString.empty()) {
                        replaceString = "null";
                    }
                    format = format.replace(it, it + 2, replaceString);
                    it = format.begin() + pos + replaceString.size() - 1;
                } else if(*(it + 1) == '{') {
                    brace = true;
                    iter_start = it+2;
                }
            } else if(brace && *it == '}') {
                // 중괄호 표현 => strftime 함수를 이용
                std::string temp(iter_start, it);

                time_t rawtime;
                struct tm* timeinfo;
                char buffer[256];
            
                time(&rawtime);
                timeinfo = localtime(&rawtime);

                if(strftime(buffer, 256, temp.c_str(), timeinfo)) {
                    std::string timeString(buffer);
                    size_t pos = std::distance(format.begin(), iter_start-2);
                    format = format.replace(iter_start-2, it + 1, timeString);                        it = format.begin() + pos + timeString.size() - 1;
                }
                brace = false;
            }
        } 
        return format;
    }

    void processing(std::vector<std::vector<Crawler::ParseData>> &data) {
        std::vector<std::pair<std::vector<Crawler::ParseData>::iterator, std::vector<Crawler::ParseData>::iterator>> iters_pairs;

        for (auto it = data.begin(); it != data.end(); ++it) {
            iters_pairs.push_back(std::make_pair<std::vector<Crawler::ParseData>::iterator, std::vector<Crawler::ParseData>::iterator>(it->begin(), it->end()));
        }

        int currentIndex = 0;
        int maxDepth = -1;
        while (true)
        {
            std::vector<Crawler::ParseData> temp;
            bool valid = false;
            for (size_t i = 0; i < iters_pairs.size(); ++i) {
                auto& placepair = iters_pairs[i];
                while (true)
                {
                    if(placepair.first != placepair.second) {
                        maxDepth = std::max(placepair.first->depth, maxDepth);
                        if (placepair.first->index == currentIndex) {
                            temp.push_back(*placepair.first);
                            std::cout << placepair.first->text << std::endl;
                            ++placepair.first;
                            if(placepair.first == placepair.second) {
                                break;
                            }
                        } else {
                            break;
                        }
                    } else {
                        if((placepair.first-1)->depth < maxDepth) {
                            temp.push_back(*(placepair.first-1));
                            std::cout << "prev :" << (placepair.first - 1)->text << std::endl;
                        }
                        break;
                    }
                }
                if(placepair.first != placepair.second) {
                    valid |= true;
                }
            }

            //std::cout << formatting(temp) << std::endl;
            std::cout << "-----" << std::endl;
            if (!valid) {
                break;
            }
            ++currentIndex;
        }
    }
};