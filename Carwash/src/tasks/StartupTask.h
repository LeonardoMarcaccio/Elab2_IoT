#ifndef __STARTUPTASK__
#define __STARTUPTASK__

#include "Task.h"
#include "../components/PIR.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"

class StartupTask : public Task {

    private :
        unsigned long *checkInTime;
        PIR *pir;
        Led *l1;
        SimpleLCD *lcd;
    
    public:
        StartupTask(int myPeriod, State *currentState, PIR *pir, Led *l1, SimpleLCD *lcd, unsigned long *checkInTime);
        void tick();
};

#endif
