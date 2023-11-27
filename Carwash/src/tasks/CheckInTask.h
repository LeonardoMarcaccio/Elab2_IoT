#ifndef __CHECKINTASK__
#define __CHECKINTASK__

#include "Task.h"
#include "../components/PIR.h"

class CheckinTask : public Task {

    private :
        int *checkInTime;
        PIR *pir;
    
    public:
        CheckinTask(int myPeriod, State *currentState, int *checkInTime, PIR *pir);
        void tick();
};

#endif