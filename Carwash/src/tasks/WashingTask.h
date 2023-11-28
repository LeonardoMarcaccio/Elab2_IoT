#ifndef __WASHINGTASK__
#define __WASHINGTASK__

#include "Task.h"

class WashingTask : public Task {

    private :
        unsigned long *washStart;
        unsigned long interval;
        unsigned long overheatStart;
        unsigned long overheatInterval;
        unsigned long standardInterval;
        unsigned long *emergencyStart;
        unsigned long *emergencyInterval;
        bool emergencyFlag;
    
    public:
        WashingTask(int myPeriod, State *currentState, unsigned long *washStart, unsigned long *emergencyStart, unsigned long *emergencyInterval);
        void tick();
};

#endif