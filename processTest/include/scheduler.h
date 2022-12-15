#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <iomanip>
#include <chrono>
#include <functional>
#include <queue>

time_t MakeLocalTime(int year, int month, int day, int hour, int minute, int second) {
    std::tm timeinfo = std::tm();
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;
    timeinfo.tm_hour = hour;
    timeinfo.tm_min = minute;
    timeinfo.tm_sec = second;
    return std::mktime(&timeinfo);
}

namespace Scheduler {

enum ScheduleType{
    SCHEDULE_ONCE = 1,
    SCHEDULE_DAILY,
    SCHEDULE_WEEKLY,
    SCHEDULE_MONTHLY
};

enum ScheduleResult {
    SKED_SUCCESS = 0,
    SKED_FAIL
};

class TimeDuration;

class TimePoint {
private:
    std::chrono::system_clock::time_point mPoint;

public:
    TimePoint() : mPoint(std::chrono::system_clock::now()) {}
    TimePoint(const TimePoint& src) = default;
    TimePoint(TimePoint&& src) = default;
    TimePoint(const std::chrono::system_clock::time_point& Point) : mPoint(Point) {}
    TimePoint(const std::chrono::system_clock::duration& Duration) : mPoint(std::chrono::system_clock::now() + Duration) {}
    TimePoint(int year, int month, int day, int hour = 0, int minute = 0, int second = 0) : mPoint(std::chrono::system_clock::from_time_t(MakeLocalTime(year, month, day, hour, minute, second))) {}

    virtual ~TimePoint() = default;
    TimePoint& operator=(const TimePoint& rhs) = default;
    TimePoint& operator=(TimePoint&& rhs) = default;
    TimePoint& operator=(const std::chrono::system_clock::time_point& rhs) {
        mPoint = rhs;
        return *this;
    }
    TimePoint& operator+=(const std::chrono::system_clock::duration& rhs) {
        mPoint += rhs;
        return *this;
    }
    TimePoint& operator-=(const std::chrono::system_clock::duration& rhs) {
        mPoint -= rhs;
        return *this;
    }

    friend TimeDuration operator-(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator==(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator!=(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator<(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator>(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator<=(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator>=(const TimePoint& lhs, const TimePoint& rhs);
    friend std::ostream& operator<<(std::ostream& ostr, const TimePoint& rhs);

    operator std::chrono::system_clock::time_point() const { return mPoint; }
};

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

class TimeDuration {
private:
    std::chrono::system_clock::duration mDuration;

public:
    TimeDuration() = default;
    TimeDuration(const TimeDuration& src) = default;
    TimeDuration(TimeDuration&& src) = default;
    TimeDuration(const std::chrono::system_clock::duration& Duration) : mDuration(Duration) {}
    TimeDuration(const TimePoint& tp1, const TimePoint& tp2) : mDuration(tp1 - tp2) {}

    virtual ~TimeDuration() = default;
    TimeDuration& operator=(const TimeDuration& rhs) = default;
    TimeDuration& operator=(TimeDuration&& rhs) = default;
    friend std::ostream& operator<<(std::ostream& ostr, const TimeDuration& rhs);

    operator std::chrono::system_clock::duration() const { return mDuration; }
};

std::ostream& operator<<(std::ostream& ostr, const TimeDuration& rhs) {
    long count = std::chrono::duration_cast<std::chrono::seconds>(rhs.mDuration).count();
    ostr << count / 3600 << ":" << (count % 3600) / 60 << ":" << count % 60;
    return ostr;
}

TimeDuration operator-(const TimePoint& lhs, const TimePoint& rhs) { return TimeDuration(lhs.mPoint - rhs.mPoint); } // class TimePoint public method

// type / interval / start / end / lastProcessTime
struct Trigger {
    ScheduleType type = ScheduleType::SCHEDULE_ONCE;

    TimePoint start = std::chrono::system_clock::time_point::min();
    TimePoint end = std::chrono::system_clock::time_point::max();

    Trigger() = default;
    Trigger(ScheduleType Type) : type(Type) {}
    Trigger(ScheduleType Type, const TimePoint& Start, const TimePoint& End) : type(Type), start(Start), end(End) {}
    Trigger(ScheduleType Type, const std::chrono::system_clock::duration& Start, const std::chrono::system_clock::duration& End) : type(Type), start(Start), end(End) {}
    inline bool contain(TimePoint Point) {
        return (start <= Point) && (Point < end);
    }
};

class Schedule {
private:
    std::string mName;
    std::string mDescription;
    ScheduleResult mResult;
    std::function<void()> mFunc;
public:

    friend bool operator<(const Schedule& lhs, const Schedule& rhs);
};

//
bool operator<(const Schedule& lhs, const Schedule& rhs) { return 0; }

class Scheduler {
private: 
std::priority_queue<Schedule> mSchedules;

public:
Scheduler();
Scheduler(const Scheduler& src);
Scheduler(Scheduler&& src) noexcept;
virtual ~Scheduler() noexcept;
Scheduler& operator=(const Scheduler& rhs);
Scheduler& operator=(Scheduler&& rhs) noexcept;

};

}


#endif