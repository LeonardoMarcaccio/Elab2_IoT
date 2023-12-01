#ifndef __EMERGENCYTASK__
#define __EMERGENCYTASK__

#include "Task.h"
#include "../components/SimpleLCD.h"
#include "../components/Button.h"

class EmergencyTask : public Task {

    private :
        SimpleLCD *lcd;
        Button *button;
        unsigned long *emergencyStart;
        unsigned long *emergencyInterval;
    
    public:
        EmergencyTask(int myPeriod, State *currentState, SimpleLCD *lcd, Button *button, unsigned long *emergencyStart, unsigned long *emergencyInterval);
        void tick();
};

#endif