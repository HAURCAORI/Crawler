#include <iostream>
#include <curlobject.h>
#include <curlthreadpool.h>
#include <curlioadapter.h>

#include <curlcrawler.h>

#include "htmlparser.h"

#include "testcode.hpp"

#include "conversion.h"

#include "scheduler.h"

#include "modifiedpriorityqueue.h"


#include <chrono>
#define BEGIN_CHRONO std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#define END_CHRONO std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - begin).count() << "[ms]" << std::endl;
/*
using namespace Scheduler;
class TestSchedule {
private:
    std::string mName;
    std::string mDescription;
    Trigger mTrigger;
    std::function<void()> mFunc;
    s_id mId;
public:
    TestSchedule() = default;
    TestSchedule(const Trigger& Trigger) : mTrigger(Trigger) {}
    TestSchedule(const std::string& Name, const std::string& Description, const Trigger& Trigger) : mName(Name), mDescription(Description), mTrigger(Trigger) {}
    TestSchedule(const TestSchedule& src) = default;
    TestSchedule(TestSchedule&& src) = default;
    TestSchedule& operator=(const TestSchedule& rhs) = default;
    TestSchedule& operator=(TestSchedule&& rhs) = default;

    void setName(const std::string& Name) { mName = Name; }
    void setDescription(const std::string& Description) { mDescription = Description; }
    std::string getName() const  { return mName; }
    std::string getDescription() const { return mDescription; }
    TimePoint getStartTime() const { return mTrigger.start; }
    TimePoint getEndTime() const { return mTrigger.end; }
    TimeDuration getInterval() const { return mTrigger.time; }

    //null

    void setEvent(std::function<void()> event) { mFunc = event; }

    bool expired() {
        if(mTrigger.type == ScheduleType::SCHEDULE_ONCE && mTrigger.count > 0) {
            return true;
        }
        if(mTrigger.end < std::chrono::system_clock::now()) {
            return true;
        }
        return false;
    }

    bool execute(const TimePoint& point) {
        if(!mTrigger.contain(point)) { return false; }

        if(mTrigger.nextProcess > point) { return false; }

        try {
            if(mFunc) {
                mFunc();
            }
        } catch(std::exception e) {
            fprintf(stderr, "Schedule execute error:%s\r\n", e.what());
            return false;
        }
        std::cout <<  mTrigger.nextProcess << std::endl;
        mTrigger.next(point);
        return true;
    }

    friend bool operator==(const TestSchedule& lhs, const TestSchedule& rhs);
    friend bool operator<(const TestSchedule& lhs, const TestSchedule& rhs);
    
    class comp {
    public:
        bool operator()(const TestSchedule& lhs, const TestSchedule& rhs) { return lhs < rhs; }
    };
};
bool operator==(const TestSchedule& lhs, const TestSchedule& rhs) { return lhs.mName == rhs.mName && lhs.mTrigger == rhs.mTrigger; }
bool operator<(const TestSchedule& lhs, const TestSchedule& rhs) { return lhs.mTrigger.nextProcess > rhs.mTrigger.nextProcess; }


class Test : std::priority_queue<TestSchedule, std::vector<TestSchedule>> {
public:
    void insert(TestSchedule a) {
        this->emplace(a);
        auto it = find(this->c.begin(), this->c.end(), a);
        std::cout << a.getName() << std::endl;
    }
};
*/

int main() {
    curl_global_init(CURL_GLOBAL_DEFAULT);
    using namespace Crawler;
    using namespace std::chrono_literals;

    using namespace Scheduler;
    
    //Test temp;
    //Trigger t(SCHEDULE_MONTHLY, TimePoint(2024,1,1), TimePoint(2025,1,1), TimeDuration(std::chrono::hours(1)));
    //TestSchedule test("a", "b", Trigger());
    //temp.insert(test);



    Scheduler::Scheduler scheduler;
    
    for(int i = 1; i < 5; i++) {
        Trigger t(SCHEDULE_MONTHLY, TimePoint(2024,i,i), TimePoint(2025,1,1), TimeDuration(std::chrono::hours(1)));
        std::string str = std::to_string(i);
        Scheduler::Schedule sch(str,str,t);
        scheduler.add(sch);
    }
    
    scheduler.printTemp();
    /*
    std::cout << scheduler.at(1).getStartTime() << std::endl;
    std::cout << scheduler.at(3).getStartTime() << std::endl;
    scheduler.count();

    
    for(int i = 1; i < 10; i++) {
        Trigger t(SCHEDULE_MONTHLY, TimePoint(2024,i,i), TimePoint(2025,1,1), TimeDuration(std::chrono::hours(1)));
        Scheduler::Schedule sch(t);
        scheduler.add(sch);
        std::cout
    }
    */
    
    
    //scheduler.flush();
    
    /*
    int iterCount = 0;
    while(iterCount < 1000) {
        sch.execute(std::chrono::system_clock::now() + std::chrono::hours(iterCount*24));
        iterCount += 1;
    }
    */



    //ParsingTest parsingtest;
    //parsingtest.excute();
/*
    Crawler::CURLCrawler object;
    object.setSaveChange(false);
    //obj.createListFile("./CrawlingLists.json", true);
    object.loadList();
    //obj.addList("A","https://www.naver.com/,","/div/div");
    auto o = object.at(2);
    o.execute();
*/
    //std::this_thread::sleep_for(1s);

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