#include <iostream>
#include <curlobject.h>
#include <curlthreadpool.h>
#include <curlioadapter.h>

#include <curlcrawler.h>

#include "htmlparser.h"

#include "testcode.hpp"

#include "scheduler.hpp"

#include <chrono>
#define BEGIN_CHRONO std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#define END_CHRONO std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << "[ms]" << std::endl;

class test{
public:
    test() { std::cout << "constructor" << std::endl; }
    virtual ~test() { std::cout << "destructor" << std::endl; }
};

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    using namespace Crawler;
    using namespace std::chrono_literals;

    //ParsingTest parsingtest;
    //parsingtest.excute();


    //Scheduler::TimePoint tp("03:30:0");
    //std::cout << tp << std::endl;
/*
    std::vector<test> vec;
    {   test te;
        vec.push_back(std::move(te));
    }
    std::this_thread::sleep_for(5s);
    std::cout << "main end" << std::endl;
    return 0;
    */

    Crawler::CURLCrawler object;
    object.setSaveChange(false);
    //obj.createListFile("./CrawlingLists.json", true);
    object.loadList();
    //std::cout << object.addList("K","https://www.naver.com/,","/div/div") << std::endl;
    //auto& o = object.at("C");
    //std::cout << o.getID() << std::endl;
    std::this_thread::sleep_for(60s);
    std::cout << "main end" << std::endl;

    //o.execute();
    

    // todo: execute 될 때 info valid 수정 경로 확인

    

    //o.setURIOptions({{"a","b"}});
    
    //o.appendOption(std::make_pair<std::string,std::string>("b","2"));
    //o.setURLPlaceholders({"ae:1","ec:2"});
    //std::cout << o.getOptions().back().second << std::endl;
    //CrawlingObjectTest::print(o);

    //CURLThreadPool threads(5);
     /*
    for(int i = 0; i < 1; i++) {
        Crawler::CURLObject obj("https://www.naver.com/");
        std::string path = "./Output/aaa1.html";
        obj.setAdapter<IOAdapterFile>();
        obj.setAdapterOption(ADAPTER_OPT_PATH, path);
        obj.appendHeader("Referer: https://new.land.naver.com/complexes?ms=37.4122794,126.6246398,17&a=APT:JGC:ABYG&e=RETAIL");
        obj.setOption(CURLOPT_VERBOSE, 1L);
        CURLThreadPool::getInstance().EnqueueCURL(std::move(obj));
    }
*/
    //HTMLTest test;
    //test.execute();
    return 0; 
    
    Crawler::CURLObject obj("https://www.naver.com/");
    if(obj) {
        std::string path = "./Output/original.html";
        obj.setAdapter<IOAdapterFile>();
        obj.setAdapterOption(ADAPTER_OPT_PATH, path);
        obj.setAdapterOption(ADAPTER_OPT_GET_ORIGINAL, false);
        obj.setAdapterOption(ADAPTER_OPT_FORMAT, "[결과 : $@], ${%X}");
        obj.setAdapterTarget({"/html/body/div[2]/div[2]/div[2]/div[1]/div[1]/ul[2]/li[1]/a", "/html/body/div[2]/div[2]/div[2]/div[1]/div[1]/ul[2]/li[2]/a"});
        obj.perform();

        /*
        std::string test_set = readFile("./Output/original.html");
        //std::string test_set = readFile("./Output/input.html");
        HTMLParser::HTMLPreprocessing(test_set);
        HTMLParser::HTMLCorrectError(test_set);
        writeFile("./Output/test.html",test_set);
        

        HTMLParser parser(&test_set);
        auto doc = parser.getDocument();
        std::cout << parser.lastNode().name() << "/" << parser.lastNode().first_attribute().value() << std::endl;
        std::cout << parser.lastNodeTag().tag << "/" << parser.lastNodeTag().attribute << std::endl;
        std::cout << "=> success? : " << parser.success() << std::endl;
        */

        //auto tool = doc->select_node(R"(/html/body/div[2]/main)"); // container
        //printNode(*doc,3);
        //auto ln = parser.lastNodeTag();
        
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }



    curl_global_cleanup();

    return 0;
}