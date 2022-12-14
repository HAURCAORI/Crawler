#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <string>
#include <iomanip>
#include <chrono>
#include <functional>

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

class TimePoint {
private:
    std::chrono::system_clock::time_point mPoint;

public:
    TimePoint() : mPoint(std::chrono::system_clock::now()) {}
    TimePoint(const TimePoint& src) = default;
    TimePoint(TimePoint&& src) = default;
    TimePoint(const std::chrono::system_clock::time_point& Point) : mPoint(Point) {}
    TimePoint(const std::chrono::system_clock::duration& Duration) : mPoint(std::chrono::system_clock::now() + Duration) {}
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
    TimePoint mLastProcessTime;
    std::function<void()> mFunc;
public:

};


class Scheduler {
private: 
    
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