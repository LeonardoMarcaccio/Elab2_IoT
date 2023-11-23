#ifndef __CHECKINTASK__
#define __CHECKINTASK__

#include "Task.h"
#include "State.h"
#include "components\PIR.h"

class CheckInTask : public Task {

    private :
        PIR *pir;
        extern State currentState
    
    public:
        CheckInTask::CheckInTask(int myPeriod, int timeElapsed);

};

#endif
