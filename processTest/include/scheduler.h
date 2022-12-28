#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <iomanip>
#include <chrono>
#include <functional>
#include <queue>
#include <unordered_map>
#include <thread>
#include <mutex>
#include <condition_variable>

#define UTC_OFFSET 9

typedef int s_id;

/**
 *  UTC time helper function;
 */
template <class Int>
constexpr Int days_from_civil(Int y, unsigned m, unsigned d) noexcept {
    static_assert(std::numeric_limits<unsigned>::digits >= 18,
             "This algorithm has not been ported to a 16 bit unsigned integer");
    static_assert(std::numeric_limits<Int>::digits >= 20,
             "This algorithm has not been ported to a 16 bit signed integer");
    y -= m <= 2;
    const Int era = (y >= 0 ? y : y-399) / 400;
    const unsigned yoe = static_cast<unsigned>(y - era * 400);      // [0, 399]
    const unsigned doy = (153*(m + (m > 2 ? -3 : 9)) + 2)/5 + d-1;  // [0, 365]
    const unsigned doe = yoe * 365 + yoe/4 - yoe/100 + doy;         // [0, 146096]
    return era * 146097 + static_cast<Int>(doe) - 719468;
}

// Returns year/month/day triple in civil calendar
// Preconditions:  z is number of days since 1970-01-01 and is in the range:
//                   [numeric_limits<Int>::min(), numeric_limits<Int>::max()-719468].
template <class Int>
constexpr std::tuple<Int, unsigned, unsigned> civil_from_days(Int z) noexcept {
    static_assert(std::numeric_limits<unsigned>::digits >= 18,
             "This algorithm has not been ported to a 16 bit unsigned integer");
    static_assert(std::numeric_limits<Int>::digits >= 20,
             "This algorithm has not been ported to a 16 bit signed integer");
    z += 719468;
    const Int era = (z >= 0 ? z : z - 146096) / 146097;
    const unsigned doe = static_cast<unsigned>(z - era * 146097);          // [0, 146096]
    const unsigned yoe = (doe - doe/1460 + doe/36524 - doe/146096) / 365;  // [0, 399]
    const Int y = static_cast<Int>(yoe) + era * 400;
    const unsigned doy = doe - (365*yoe + yoe/4 - yoe/100);                // [0, 365]
    const unsigned mp = (5*doy + 2)/153;                                   // [0, 11]
    const unsigned d = doy - (153*mp+2)/5 + 1;                             // [1, 31]
    const unsigned m = mp + (mp < 10 ? 3 : -9);                            // [1, 12]
    return std::tuple<Int, unsigned, unsigned>(y + (m <= 2), m, d);
}

template <class Int>
constexpr unsigned weekday_from_days(Int z) noexcept {
    return static_cast<unsigned>(z >= -4 ? (z+4) % 7 : (z+5) % 7 + 6);
}

template <class To, class Rep, class Period>
To round_down(const std::chrono::duration<Rep, Period>& d) {
    To t = std::chrono::duration_cast<To>(d);
    if (t > d)
        --t;
    return t;
}


template <class Duration>
std::tm make_tm_from_UTC(std::chrono::time_point<std::chrono::system_clock, Duration> tp, int convertLocal = 0) {
    using namespace std;
    using namespace std::chrono;
    typedef duration<int, ratio_multiply<hours::period, ratio<24>>> days;
    // t is time duration since 1970-01-01
    Duration t = tp.time_since_epoch();
    // d is days since 1970-01-01
    days d = round_down<days>(t);
    // t is now time duration since midnight of day d
    t -= d;
    // break d down into year/month/day
    int year;
    unsigned month;
    unsigned day;
    std::tie(year, month, day) = civil_from_days(d.count());
    // start filling in the tm with calendar info
    std::tm tm = {0};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_wday = weekday_from_days(d.count());
    tm.tm_yday = d.count() - days_from_civil(year, 1, 1);
    // Fill in the time
    t += hours(convertLocal); // 체크 필요
    tm.tm_hour = duration_cast<hours>(t).count();
    t -= hours(tm.tm_hour);
    tm.tm_min = duration_cast<minutes>(t).count();
    t -= minutes(tm.tm_min);
    tm.tm_sec = duration_cast<seconds>(t).count();
    return tm;
}

/**
 *  local_time get function
 */
time_t make_local_time(int year, int month, int day, int hour, int minute, int second) {
    std::tm timeinfo = std::tm();
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = second;
    return std::mktime(&timeinfo);
}

/**
 *  string to time_t function
 */
bool make_local_time(const std::string& str, std::tm* timeinfo) {
    bool setdate = false;
    int count = 0, temp = 0;
    for(auto it = str.begin(); it != str.end(); ++it) {
        if(isdigit(*it)) { temp *= 10; temp += *it - '0'; continue; }
        if(count == 0) {
            if(*it == '-' || *it == '.') {
                if(setdate) { continue; }
                if(temp > 9999) { return false; }
                if(temp < 100) { temp += 2000; }
                timeinfo->tm_year = temp - 1900;
                temp = 0; setdate = true; ++count;
            } else if(*it == ':') {
                if(temp > 24) { return false; }
                timeinfo->tm_hour = temp;
                temp = 0; setdate = false; ++count;
            }
        } else if(count == 1) {
            if(*it == '-' || *it == '.') {
                if(temp > 12) { return false; }
                timeinfo->tm_mon = temp - 1;
                temp = 0; ++count;
            } else if(*it == ':') {
                if(temp > 60) { return false; }
                timeinfo->tm_min = temp;
                temp = 0; ++count;
            }
        } else if(count == 2) {
            if(*it == ' ' || *it == '.') {
                if(setdate) {
                    if(temp > 31) { return false; }
                    timeinfo->tm_mday = temp;
                } else {
                    if(temp > 60) { return false; }
                    timeinfo->tm_sec = temp;
                }
                temp = 0; count = 0;
            }
        }
    }
    if(count == 2) {
        if(setdate) {
            if(temp > 31) { return false; }
            timeinfo->tm_mday = temp;
        } else {
            if(temp > 60) { return false; }
            timeinfo->tm_sec = temp;    
        }
    }
    return true;
}


/**
 *  namespace Scheduler
 */
namespace Scheduler {

// Scheduler variables
enum ScheduleType{
    SCHEDULE_ONCE = 1,
    SCHEDULE_INTERVAL,
    SCHEDULE_DAILY,
    SCHEDULE_WEEKLY,
    SCHEDULE_MONTHLY
};

enum ScheduleResult {
    SKED_SUCCESS = 0,
    SKED_WAIT,
    SKED_EXPIRED,
    SKED_FAIL
};

// Forward declaration of TimeDuration.
class TimeDuration;

/**
 *  TimePoint Object(Wrapper of std::chrono::system_clock::time_point)
 */
class TimePoint {
private:
    std::chrono::system_clock::time_point mPoint;

public:
    // Constructor
    TimePoint() : mPoint(std::chrono::system_clock::now()) {}
    TimePoint(const TimePoint& src) = default;
    TimePoint(TimePoint&& src) = default;
    TimePoint(const std::chrono::system_clock::time_point& Point) : mPoint(Point) {}
    TimePoint(const std::chrono::system_clock::duration& Duration) : mPoint(std::chrono::system_clock::now() + Duration) {}
    TimePoint(int year, int month, int day, int hour = 0, int minute = 0, int second = 0)
             : mPoint(std::chrono::system_clock::from_time_t(make_local_time(year, month, day, hour, minute, second))) {}
    TimePoint(const std::string& str) {
        if(str.empty()) { mPoint = std::chrono::system_clock::now(); return; }
        std::tm time = {};
        if(make_local_time(str, &time)) {
            mPoint = std::chrono::system_clock::from_time_t(std::mktime(&time));
        } else {
            throw std::invalid_argument("TimePoint invalid argument.");
        }
    }


    // Destructor
    virtual ~TimePoint() = default;

    // Assignment
    TimePoint& operator=(const TimePoint& rhs) = default;
    TimePoint& operator=(TimePoint&& rhs) = default;
    TimePoint& operator=(const std::chrono::system_clock::time_point& rhs) { mPoint = rhs; return *this; }
    TimePoint& operator+=(const std::chrono::system_clock::duration& rhs) { mPoint += rhs; return *this; }
    TimePoint& operator-=(const std::chrono::system_clock::duration& rhs) { mPoint -= rhs; return *this; }

    // Method
    std::chrono::system_clock::time_point get() { return mPoint; }
    static TimePoint now() { return TimePoint(std::chrono::system_clock::now()); }

    // TimePoint and TimeDuration operators
    friend TimePoint operator+(const TimePoint& lhs, const TimeDuration& rhs);
    friend TimePoint operator+(const TimeDuration& lhs, const TimePoint& rhs);
    friend TimePoint operator-(const TimePoint& lhs, const TimeDuration& rhs);
    friend TimeDuration operator-(const TimePoint& lhs, const TimePoint& rhs);

    // Relational operators
    friend bool operator==(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator!=(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator<(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator>(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator<=(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator>=(const TimePoint& lhs, const TimePoint& rhs);

    // Stream operator
    friend std::ostream& operator<<(std::ostream& ostr, const TimePoint& rhs);

    // Type cast operator
    operator std::chrono::system_clock::time_point() const { return mPoint; }
};

// TimePoint oprators define
bool operator==(const TimePoint& lhs, const TimePoint& rhs) { return lhs.mPoint == rhs.mPoint; };
bool operator!=(const TimePoint& lhs, const TimePoint& rhs) { return !(operator==(lhs, rhs)); };
bool operator<(const TimePoint& lhs, const TimePoint& rhs) { return lhs.mPoint < rhs.mPoint; };
bool operator>(const TimePoint& lhs, const TimePoint& rhs) { return operator<(rhs, lhs); };
bool operator<=(const TimePoint& lhs, const TimePoint& rhs) { return !(operator>(lhs, rhs)); };
bool operator>=(const TimePoint& lhs, const TimePoint& rhs) { return !(operator<(lhs, rhs)); };
std::ostream& operator<<(std::ostream& ostr, const TimePoint& rhs) {
    const std::time_t t_c = std::chrono::system_clock::to_time_t(rhs.mPoint);
    ostr << std::put_time(std::localtime(&t_c), "%F %T");
    return ostr;
}

/**
 *  TimeDuration Object(Wrapper of std::chrono::system_clock::duration)
 */
class TimeDuration {
private:
    std::chrono::system_clock::duration mDuration;

public:
    // Constructor
    TimeDuration() = default;
    TimeDuration(const TimeDuration& src) = default;
    TimeDuration(TimeDuration&& src) = default;
    TimeDuration(const std::chrono::system_clock::duration& Duration) : mDuration(Duration) {}
    TimeDuration(const TimePoint& tp1, const TimePoint& tp2) : mDuration(tp1 - tp2) {}
    TimeDuration(int hour, int minute, int second) {
        mDuration = std::chrono::hours(hour);
        mDuration += std::chrono::minutes(minute);
        mDuration += std::chrono::seconds(second);
    }
    TimeDuration(int day, int hour, int minute, int second) : TimeDuration(hour + day*24, minute, second) {}

    // Destructor
    virtual ~TimeDuration() = default;

    // Assignment
    TimeDuration& operator=(const TimeDuration& rhs) = default;
    TimeDuration& operator=(TimeDuration&& rhs) = default;

    // Method
    std::chrono::system_clock::duration get() { return mDuration; }

    // TimePoint and TimeDuration operators
    friend TimePoint operator+(const TimePoint& lhs, const TimeDuration& rhs);
    friend TimePoint operator+(const TimeDuration& lhs, const TimePoint& rhs);
    friend TimePoint operator-(const TimePoint& lhs, const TimeDuration& rhs);

    // Relational operator
    friend bool operator==(const TimeDuration& lhs, const TimeDuration& rhs);

    // Stream operator
    friend std::ostream& operator<<(std::ostream& ostr, const TimeDuration& rhs);

    // Type cast
    operator std::chrono::system_clock::duration() const { return mDuration; }
};

// TimeDuration oprators define
bool operator==(const TimeDuration& lhs, const TimeDuration& rhs) { return lhs.mDuration == rhs.mDuration; }
std::ostream& operator<<(std::ostream& ostr, const TimeDuration& rhs) {
    long count = std::chrono::duration_cast<std::chrono::seconds>(rhs.mDuration).count();
    ostr << count / 3600 << ":" << (count % 3600) / 60 << ":" << count % 60;
    return ostr;
}

// time_point & duration operators
TimePoint operator+(const TimePoint& lhs, const TimeDuration& rhs) { return TimePoint(lhs.mPoint + rhs.mDuration); }
TimePoint operator+(const TimeDuration& lhs, const TimePoint& rhs) { return TimePoint(lhs.mDuration + rhs.mPoint); }
TimePoint operator-(const TimePoint& lhs, const TimeDuration& rhs) { return TimePoint(lhs.mPoint - rhs.mDuration); }
TimeDuration operator-(const TimePoint& lhs, const TimePoint& rhs) { return TimeDuration(lhs.mPoint - rhs.mPoint); } 


/**
 *  Trigger Object(class of time informations)
 */
struct Trigger {
    // Variables
    ScheduleType type = ScheduleType::SCHEDULE_ONCE;
    TimePoint start = std::chrono::system_clock::time_point::min();
    TimePoint end = std::chrono::system_clock::time_point::max();
    TimeDuration time = TimeDuration();
    TimePoint lastProcess = std::chrono::system_clock::time_point::min();
    TimePoint nextProcess = std::chrono::system_clock::time_point::min();
    int count = 0;

    // Constructor
    Trigger() { initInterval(); };
    Trigger(ScheduleType Type) : type(Type) { initInterval(); }
    Trigger(ScheduleType Type, const TimePoint& Start, const TimePoint& End) : type(Type), start(Start), end(End) { initInterval(); }
    Trigger(ScheduleType Type, const TimePoint& Start, const TimePoint& End, const TimeDuration& Time) : type(Type), start(Start), end(End), time(Time) { initInterval(); }

    // Methods
    inline bool inRange(const TimePoint& Point) { return (start <= Point) && (Point < end); }

    bool next(const TimePoint& point) {
        count++;
        lastProcess = nextProcess;
        if(type == ScheduleType::SCHEDULE_MONTHLY) {
            std::tm timeinfo = make_tm_from_UTC((std::chrono::system_clock::time_point) lastProcess, UTC_OFFSET);
            timeinfo.tm_mon += 1;
            nextProcess = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));
            time = nextProcess - lastProcess;
        } else {
            nextProcess += time;
        }

        if(nextProcess < point) {
            // Scheduler의 문제로 execute 수행 못한 채 상당시간 지났을 경우 처리
            //std::cout << "skip" << std::endl;
            return true; 
        } 
        return false;
    }

    // Relational operator
    friend bool operator==(const Trigger& lhs, const Trigger& rhs);
private:
    void initInterval() {
        lastProcess = start;
        nextProcess = start;
        switch(type) {
            case ScheduleType::SCHEDULE_ONCE:
                time = TimeDuration();
            break;
            case ScheduleType::SCHEDULE_INTERVAL:
                if(time == TimeDuration()) {
                    time = end - start;
                }
            break;
            case ScheduleType::SCHEDULE_DAILY:
                time = TimeDuration(24,0,0);
            break;
            case ScheduleType::SCHEDULE_WEEKLY:
                time = TimeDuration(168,0,0);
            break;
            case ScheduleType::SCHEDULE_MONTHLY: {
                std::tm timeinfo = make_tm_from_UTC((std::chrono::system_clock::time_point) start, UTC_OFFSET);
                timeinfo.tm_mon += 1;
                std::chrono::system_clock::time_point afterMonth = std::chrono::system_clock::from_time_t(std::mktime(&timeinfo));
                time = afterMonth - lastProcess;
            }
            break;
            default:
                fprintf(stderr, "ScheduleType error in Trigger.\r\n");
            break;
        }
    }
};

// Trigger operator define
bool operator==(const Trigger& lhs, const Trigger& rhs) { return lhs.type == rhs.type && lhs.start == lhs.start && lhs.end == rhs.end; }


/**
 *  Schedule Object
 */
class Schedule {
private:
    std::string mName;
    std::string mDescription;
    Trigger mTrigger;
    std::function<void()> mFunc;
    s_id mId;
public:
    // Constructor
    Schedule() = default;
    Schedule(const Trigger& Trigger) : mTrigger(Trigger) {}
    Schedule(const std::string& Name, const std::string& Description, const Trigger& Trigger) : mName(Name), mDescription(Description), mTrigger(Trigger) {}
    Schedule(const Schedule& src) = default;
    Schedule(Schedule&& src) = default;

    // Destructor
    virtual ~Schedule() = default;

    // Assignment
    Schedule& operator=(const Schedule& rhs) = default;
    Schedule& operator=(Schedule&& rhs) = default;

    // Getter, Setter
    void setName(const std::string& Name) { mName = Name; }
    void setDescription(const std::string& Description) { mDescription = Description; }
    void setEvent(std::function<void()> event) { mFunc = event; }
    std::string getName() const  { return mName; }
    std::string getDescription() const { return mDescription; }
    TimePoint getStartTime() const { return mTrigger.start; }
    TimePoint getEndTime() const { return mTrigger.end; }
    TimeDuration getInterval() const { return mTrigger.time; }
    TimePoint getLastProcessTime() const { return mTrigger.lastProcess; }
    TimePoint getNextProcessTime() const { return mTrigger.nextProcess; }
    
    void setStartTime(const TimePoint& tp) { mTrigger.start = tp; }

    // Methods
    bool expired(const TimePoint& time) {
        if(mTrigger.type == ScheduleType::SCHEDULE_ONCE && mTrigger.count > 0) { return true; }
        if(mTrigger.end < time) { return true; }
        return false;
    }

    bool executable(const TimePoint& time) { return mTrigger.nextProcess < time; }

    ScheduleResult execute() {
        TimePoint time = std::chrono::system_clock::now();
        if(expired(time)) { return ScheduleResult::SKED_EXPIRED; }
        if(!executable(time)) { return ScheduleResult::SKED_WAIT; }

        try {
            if(mFunc) {
                mFunc();
            }
        } catch(std::exception e) {
            fprintf(stderr, "Schedule execute error:%s\r\n", e.what());
            return ScheduleResult::SKED_FAIL;
        }
        
        while(mTrigger.next(time));
        return ScheduleResult::SKED_SUCCESS;
    }

    bool empty() { return *this == EmptySchedule(); }

    // Relational operators
    friend bool operator==(const Schedule& lhs, const Schedule& rhs);
    friend bool operator<(const Schedule& lhs, const Schedule& rhs);
    
    // etc.
    static Schedule& EmptySchedule() { static Schedule sch; return sch; }
    friend class Scheduler;
};

// Schedule operators define
bool operator==(const Schedule& lhs, const Schedule& rhs) { return lhs.mName == rhs.mName && lhs.mTrigger == rhs.mTrigger; }
bool operator<(const Schedule& lhs, const Schedule& rhs) { return lhs.mTrigger.nextProcess > rhs.mTrigger.nextProcess; }



/**
 *  Modified priority queue(insert, remove)
 */
class schedule_priority_queue : public std::priority_queue<Schedule, std::vector<Schedule>>{
  public:
    // insert : Emplace object into the queue and return it's reference.
    Schedule& insert(const Schedule& sch) {
        this->emplace(sch);
        return *(std::find(this->c.begin(), this->c.end(), sch));
    }
    
    // remove : Remove object by object reference.
    bool remove(const Schedule& sch) {
        auto it = std::find(this->c.begin(), this->c.end(), sch);
        if (it == this->c.end()) {
            return false;
        }
        if (it == this->c.begin()) {
            // deque the top element
            this->pop();
        }    
        else {
            // remove element and re-heap
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
        }
        return true;
    }

    // print
    void print() {
        for(auto it = this->c.begin(); it != c.end(); ++it) {
            std::cout << it->getName() << ":" << it->getNextProcessTime() << std::endl; 
        }
    }
};

/**
 *  Scheduler
 */
class Scheduler{
private: 
    schedule_priority_queue mSchedules;
    std::unordered_map<int, Schedule&> um_id_name;
    std::thread mThread = std::thread([this]() { this->WorkerThread(); });
    std::condition_variable cv_job_q_;
    std::mutex m_job_q_;
    TimeDuration mWaitTime = TimeDuration(0,0,3);
    bool mStop = false;
    bool mSuccess = false;
    int mCounter = 1;

protected:

void WorkerThread() {
    while(true) {
        std::unique_lock<std::mutex> lock(m_job_q_);
        cv_job_q_.wait_for(lock, mWaitTime.get(), [this]() { return (mSuccess && !mSchedules.empty()) || mStop; });
        if(mStop) { return; }
        std::cout << TimePoint::now() << " - thread" << std::endl;
        if(mSchedules.empty()) { continue; }
        //mSchedules.print();

        auto job = mSchedules.top();
        mSchedules.pop();
        lock.unlock();
        
        auto ret = job.execute();

        lock.lock();
        if(ret == ScheduleResult::SKED_SUCCESS) {
            mSuccess = true;
            mSchedules.emplace(job);
        } else if(ret == ScheduleResult::SKED_WAIT) {
            mSuccess = false;
            mSchedules.emplace(job);
        } else {
            mSuccess = false;
        }
        lock.unlock();

        
    }
}

public:
    // Constructor
    Scheduler() = default;
    Scheduler(const Scheduler& src) = default;
    Scheduler(Scheduler&& src) = default;

    // Destructor
    virtual ~Scheduler() noexcept { stop();}
    
    // Assignment
    Scheduler& operator=(const Scheduler& rhs) = default;
    Scheduler& operator=(Scheduler&& rhs) = default;

    // Methods
    void start() {
        if(!mStop) { return; }
        mStop = false;
        mThread = std::thread([this]() { this->WorkerThread(); });
        cv_job_q_.notify_all();
    }

    void stop() {
        if(mStop) { return; }
        mStop = true;
        mSuccess = false;
        cv_job_q_.notify_all();
        mThread.join(); 
    }

    s_id add(const Schedule& schedule) {
        std::unique_lock<std::mutex> lock(m_job_q_);
        um_id_name.insert(std::make_pair( mCounter, std::ref(mSchedules.insert(schedule)) ));
        cv_job_q_.notify_one();
        return mCounter++;
    }


    bool remove(s_id id) {
        auto it = um_id_name.find(id);
        if(it == um_id_name.end()) {
            return false;
        }
        std::unique_lock<std::mutex> lock(m_job_q_);
        mSchedules.remove(it->second);
        um_id_name.erase(it);
        return true;
    }

    Schedule& at(s_id id) {
        auto it = um_id_name.find(id);
        if(it == um_id_name.end()) {
            throw std::out_of_range("out of range");
        }
        return it->second;
    }

    const Schedule& at(s_id id) const {
        auto it = um_id_name.find(id);
        if(it == um_id_name.end()) {
            throw std::out_of_range("out of range");
        }
        return it->second;
    }


    void flush() {
        std::unique_lock<std::mutex> lock(m_job_q_);
        while (!mSchedules.empty()) {
            auto s = mSchedules.top();
            s.execute();
            mSchedules.pop();
        }
        um_id_name.clear();
    }

    void clear() {
        std::unique_lock<std::mutex> lock(m_job_q_);
        while(!mSchedules.empty()) {
            mSchedules.pop();
        }
        um_id_name.clear();
    }

    Schedule& operator[](s_id id) {
        auto it = um_id_name.find(id);
        if(it == um_id_name.end()) { return Schedule::EmptySchedule(); }
        return it->second;
    }
};

} // namespace of Scheduler


#endif