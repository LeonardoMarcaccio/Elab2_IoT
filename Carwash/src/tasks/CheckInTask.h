#ifndef __CHECKINTASK__
#define __CHECKINTASK__

#include "Task.h"
#include "../components/PIR.h"

class CheckinTask : public Task {

    private :
        unsigned long *checkInTime;
        PIR *pir;
        unsigned long N1;
    
    public:
        CheckinTask(int myPeriod, State *currentState, PIR *pir, unsigned long *checkInTime);
        void tick();
};

#endif