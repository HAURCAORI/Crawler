#include <iostream>
#include <curlobject.h>
#include <curlthreadpool.h>
#include <curlioadapter.h>

int main() {
    std::cout << "a" << std::endl;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    using namespace Crawler;


    //IOAdapter adapter;
    //adapter.set(1234);
    //adapter.out();
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
        std::string path = "abcde";
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