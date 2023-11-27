#ifndef __STARTUPTASK__
#define __STARTUPTASK__

#include "Task.h"
#include "../components/PIR.h"

class StartupTask : public Task {

    private :
        int *checkInTime;
        PIR *pir;
    
    public:
        StartupTask(int myPeriod, State *currentState, int *checkInTime, PIR *pir);
        void tick();
};

#endif
