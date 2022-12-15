#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <iomanip>
#include <chrono>
#include <functional>
#include <queue>

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
    TimePoint(long years, long months, long days, long hours = 0, long minutes = 0, long seconds = 0) {
        mPoint += std::chrono::duration<long, std::ratio<31556952>>(years - 1969);
    
        //mPoint += std::chrono::duration<long, std::ratio<2629746>>(months);
        //mPoint += std::chrono::duration<long, std::ratio<86400>>(days);
        //mPoint += std::chrono::duration<long, std::ratio<3600>>(hours);
        //mPoint += std::chrono::duration<long, std::ratio<60>>(minutes);
        //mPoint += std::chrono::duration<long, std::ratio<1>>(seconds);
    }

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

    TimeDuration(const TimePoint& tp1, const TimePoint& tp2) {}

    virtual ~TimeDuration() = default;
    TimeDuration& operator=(const TimeDuration& rhs) = default;
    TimeDuration& operator=(TimeDuration&& rhs) = default;

    operator std::chrono::system_clock::duration() const { return mDuration; }
};

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