#ifndef _SLEEPTASK_
#define _SLEEPTASK_

#include "Task.h"
#include "../components/Led.h"

class SleepTask : public Task {
    public:
        State *currentState;
        int interruptPin;
        Led *l1;
        Led *l2;
        Led *l3;
    public:
        SleepTask(int myPeriod, State *currentState, int interruptPin, Led *l1, Led *l2, Led *l3);
        void tick();
};

#endif
