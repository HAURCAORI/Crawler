#include <iostream>
#include <curlobject.h>
#include <curlthreadpool.h>
#include <curlioadapter.h>

#include "htmlparser.h"

#include "testcode.hpp"

#include <chrono>
#define BEGIN_CHRONO std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#define END_CHRONO std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << "[ms]" << std::endl;


void printNode(Crawler::HTMLParser::xmlNode target, size_t deep) {
    std::cout << target.path() << " : " << target.first_attribute().value() << std::endl;
    if(deep == 0) {
        return;
    }
    deep--;
    for (auto node = target.first_child(); node; node = node.next_sibling())
    {
        printNode(node, deep);
    }
}

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    using namespace Crawler;

    /* [HTMLPreprocessing Test Code]
    std::string test_set = readFile("./Output/input.html");
    HTMLParser::HTMLPreprocessing(test_set);
    writeFile("./Output/test.html",test_set);
    */

    /*
    BEGIN_CHRONO
    for(int i = 0; i < 1; i++) {
        auto tool = doc->select_node(R"(/html/body)");
        std::cout << tool.node() << std::endl;
    }
    END_CHRONO
    */

   /*
    CURLThreadPool threads(5);
    for(int i = 0; i < 1; i++) {
        Crawler::CURLObject obj("https://www.naver.com/");
        obj.setAdapter(IOAdapter());
        threads.EnqueueCURL(std::move(obj));
    }
    */

    Crawler::CURLObject obj("https://www.naver.com/");
    if(obj) {
        //CURLMultiObject::setTimeOut(100);
        std::string path = "./Output/original.html";
        obj.setAdapter<IOAdapterFile>();
        obj.setAdapterOption(ADAPTER_OPT_PATH, path);
        
        auto res = obj.perform();
        
        //obj.getAdapter()->out();
        
        CURLObject* memory;
        curl_easy_getinfo(obj, CURLINFO_PRIVATE, &memory);

        
        //std::string test_set = readFile("./Output/original.html");
        std::string test_set = readFile("./Output/input.html");
        HTMLParser::HTMLPreprocessing(test_set);
        HTMLParser::HTMLCorrectError(test_set);
        writeFile("./Output/test.html",test_set);
        

        HTMLParser parser(&test_set);
        auto doc = parser.getDocument();
        //auto tool = doc->select_node(R"(/html/body/div[2]/main)"); // container
        //printNode(tool.node(),5);
        //std::cout << "==" << std::endl;
        //printNode(doc->root(), 5);
        auto ln = parser.lastNodeTag();
        std::cout << parser.success() << std::endl;
        if(res == CURLE_OK)
            std::cout << "OK" << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }

    curl_global_cleanup();
    /*
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.naver.com/");


        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    */

    return 0;
}