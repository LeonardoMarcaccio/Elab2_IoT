#ifndef __OPENGATETASK__
#define __OPENGATETASK__

#include "Task.h"
#include "../components/PIR.h"

class OpenGateTask : public Task {

    private :
        int *checkInTime;
        PIR *pir;
    
    public:
        OpenGateTask(int myPeriod, State *currentState, int *checkInTime, PIR *pir);
        void tick();
};

#endif