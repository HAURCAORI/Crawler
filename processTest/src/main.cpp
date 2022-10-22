#include <iostream>
#include <curlobject.h>
#include <curlthreadpool.h>
#include <curlioadapter.h>

#include "htmlparser.h"
#include <chrono>
#include "test.h"

#define BEGIN_CHRONO std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#define END_CHRONO std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << "[ms]" << std::endl;




int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    using namespace Crawler;


    HTMLParser parser(&example);
    auto doc = parser.getDocument();

    auto target = doc->first_child();
    for(auto node = target.first_child(); node; node = node.next_sibling()) {
        std::cout << node.name() << std::endl;
    }
    /*
    BEGIN_CHRONO
    for(int i = 0; i < 1; i++) {
        auto tool = doc->select_node(R"(/html/body)");
        std::cout << tool.node() << std::endl;
    }
    END_CHRONO
    //IOAdapter adapter;
    //adapter.set(1234);
    //adapter.out();
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
        //std::cout << mobj.getTimeOut() << std::endl;
        //CURLMultiObject::setTimeOut(100);
        //std::cout << mobj.getTimeOut() << std::endl;
        std::string path = "./Output/test";
        obj.setAdapter<IOAdapterFile>();
        obj.setAdapterOption(ADAPTER_OPT_PATH, path);
        
        auto res = obj.perform();
        CURLObject* memory;
        curl_easy_getinfo(obj, CURLINFO_PRIVATE, &memory);
        //std::cout << memory->getData() << std::endl;

        obj.getAdapter()->out();

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