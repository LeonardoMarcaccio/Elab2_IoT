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
        EmergencyTask(int myPeriod, State *currentState, SimpleLCD *lcd, unsigned long *emergencyStart, unsigned long *emergencyInterval);
        void tick();
};

#endif