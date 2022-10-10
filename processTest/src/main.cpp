#include <iostream>
#include <curlobj.h>

int main() {
    std::cout << "a" << std::endl;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    /*
    Crawler::CURLObject obj("https://www.naver.com/");
    if(obj) {
        auto res = obj.perform();
        if(res == CURLE_OK)
            std::cout << "OK" << std::endl;
    } else {
        std::cout << "null" << std::endl;
    }
    */
    std::cout <<  Crawler::HTMLHeaderString.at(Crawler::HTMLHeader::pragma) << std::endl;
    
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