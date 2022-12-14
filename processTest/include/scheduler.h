#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <chrono>

namespace Scheduler {

enum ScheduleType{
    ONCE = 1,
    DAILY,
    WEEKLY,
    MONTHLY
};

enum ScheduleResult {
    SCHEDULE_SUCCESS = 0,
    SCHEDULE_FAIL
};

class TimePoint {
private:
    std::chrono::system_clock::time_point mPoint;

public:
    TimePoint() : mPoint(std::chrono::system_clock::time_point::min()) {}
    TimePoint(const TimePoint& src) = default;
    TimePoint(TimePoint&& src) = default;
    TimePoint(const std::chrono::system_clock::time_point& Point) : mPoint(Point) {}
    virtual ~TimePoint() = default;
    TimePoint& operator=(const TimePoint& rhs) = default;
    TimePoint& operator=(TimePoint&& rhs) = default;
    TimePoint& operator=(const std::chrono::system_clock::time_point& rhs) {
        mPoint = rhs;
        return *this;
    }

    friend bool operator==(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator!=(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator<(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator>(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator<=(const TimePoint& lhs, const TimePoint& rhs);
    friend bool operator>=(const TimePoint& lhs, const TimePoint& rhs);
};

bool operator==(const TimePoint& lhs, const TimePoint& rhs) { return lhs.mPoint == rhs.mPoint; };
bool operator!=(const TimePoint& lhs, const TimePoint& rhs) { return !(operator==(lhs, rhs)); };
bool operator<(const TimePoint& lhs, const TimePoint& rhs) { return lhs.mPoint < rhs.mPoint; };
bool operator>(const TimePoint& lhs, const TimePoint& rhs) { return operator<(rhs, lhs); };
bool operator<=(const TimePoint& lhs, const TimePoint& rhs) { return !(operator>(lhs, rhs)); };
bool operator>=(const TimePoint& lhs, const TimePoint& rhs) { return !(operator<(lhs, rhs)); };



struct Trigger {
    ScheduleType type = ScheduleType::ONCE;
    TimePoint start = std::chrono::system_clock::time_point::min();
    TimePoint end = std::chrono::system_clock::time_point::max();

    Trigger() = default;
    Trigger(ScheduleType Type) : type(Type) {}
    Trigger(ScheduleType Type, TimePoint Start, TimePoint End) : type(Type), start(Start), end(End) {}
    inline bool contain(TimePoint Point) {
        return (start <= Point) && (Point < end);
    }
};

class Schedule {
private:

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