#ifndef __WASHINGTASK__
#define __WASHINGTASK__

#include "Task.h"

class WashingTask : public Task {

    private :
        unsigned long *washStartTime;
        unsigned long interval;
        unsigned long overheatStart;
        unsigned long overheatInterval;
    
    public:
        WashingTask(int myPeriod, State *currentState, unsigned long *washStartTime);
        void tick();
};

#endif