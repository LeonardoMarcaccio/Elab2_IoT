#ifndef __EMERGENCYTASK__
#define __EMERGENCYTASK__

#include "Task.h"
#include "../components/SimpleLCD.h"
#include "../components/Button.h"
#include "../components/SerialPC/SerialPC.h"

class EmergencyTask : public Task {

    private :
        SerialPC *console;
        SimpleLCD *lcd;
        unsigned long *emergencyStart;
        unsigned long *emergencyInterval;
    
    public:
        EmergencyTask(int myPeriod, State *currentState, SerialPC *console, SimpleLCD *lcd, unsigned long *emergencyStart, unsigned long *emergencyInterval);
        void tick();
};

#endif