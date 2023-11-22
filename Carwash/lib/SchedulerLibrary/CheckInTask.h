#ifndef __CHECKINTASK__
#define __CHECKINTASK__

#include "Task.h"
#include "components\PIR.h"

class CheckInTask : public Task {

    private :
        PIR *pir;

    
    public:
        CheckInTask::CheckInTask(int myPeriod, int timeElapsed);

        /*
        virtual void init(int period){
            myPeriod = period;  
            timeElapsed = 0;
        }

        virtual void tick() = 0;
        */
};

#endif
