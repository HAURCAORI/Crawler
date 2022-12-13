#ifndef SCHEDULER_H
#define SCHEDULER_H

namespace Scheduler {

enum class {

}

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