#ifndef __STARTUPTASK__
#define __STARTUPTASK__

#include "Task.h"
#include "../components/PIR.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/Motors/Servo/Gate/Gate.h"

class StartupTask : public Task {

    private :
        unsigned long awakeTime;
        unsigned long *checkInTime;
        unsigned long N1;
        bool entered;
        PIR *pir;
        Gate *gate;
        Led *l1;
        SimpleLCD *lcd;
    
    public:
        StartupTask(int myPeriod, State *currentState, PIR *pir, Gate *gate, Led *l1, SimpleLCD *lcd, unsigned long *checkInTime);
        void tick();
};

#endif
