#ifndef __CHECKINTASK__
#define __CHECKINTASK__

#include "Task.h"
#include "components\PIR.h"

class CheckInTask : public Task {

    private :
        int *checkInTime;
        PIR *pir;
    
    public:
        CheckInTask::CheckInTask(int myPeriod, int *checkInTime, PIR *pir);
        void tick();
};

#endif
