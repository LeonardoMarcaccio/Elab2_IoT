#ifndef __EMERGENCYTASK__
#define __EMERGENCYTASK__

#include "Task.h"
#include "../components/SimpleLCD.h"

class EmergencyTask : public Task {

    private :
        SimpleLCD *lcd;
        unsigned long *emergencyStart;
        unsigned long *emergencyInterval;
    
    public:
        EmergencyTask(int myPeriod, unsigned long *emergencyStart, unsigned long *emergencyInterval, State *currentState, SimpleLCD *lcd);
        void tick();
};

#endif