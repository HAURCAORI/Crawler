#include <iostream>
#include <curlobject.h>
#include <curlthreadpool.h>
#include <curlioadapter.h>

#include "htmlparser.h"

#include "testcode.hpp"

#include <chrono>
#define BEGIN_CHRONO std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#define END_CHRONO std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << "[ms]" << std::endl;

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    using namespace Crawler;

    using namespace std::chrono_literals;
    //std::this_thread::sleep_for(3s);

    CURLThreadPool threads(5);
    
    for(int i = 0; i < 1; i++) {
        Crawler::CURLObject obj("https://www.naver.com/");
        std::string path = "./Output/aaa" + std::to_string(i) + ".html";
        obj.setAdapter<IOAdapterFile>();
        obj.setAdapterOption(ADAPTER_OPT_PATH, path);

        threads.EnqueueCURL(std::move(obj));
    }
    
    
    

    //HTMLTest test;
    //test.execute();
    return 0; 
    /*
    Crawler::CURLObject obj("https://www.dcinside.com/");
    if(obj) {
        std::string path = "./Output/original.html";
        obj.setAdapter<IOAdapterFile>();
        obj.setAdapterOption(ADAPTER_OPT_PATH, path);
        obj.setAdapterOption(ADAPTER_OPT_GET_ORIGINAL, true);
        
        //auto res = obj.perform();
        
        CURLObject* memory;
        curl_easy_getinfo(obj, CURLINFO_PRIVATE, &memory);

        
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
        
        //auto tool = doc->select_node(R"(/html/body/div[2]/main)"); // container
        //printNode(*doc,3);
        //auto ln = parser.lastNodeTag();
        
        //if(res == CURLE_OK)
            std::cout << "OK" << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }
*/


    curl_global_cleanup();

    return 0;
}