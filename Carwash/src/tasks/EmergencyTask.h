#ifndef __EMERGENCYTASK__
#define __EMERGENCYTASK__

#include "Task.h"
#include "../components/SimpleLCD.h"

class EmergencyTask : public Task {

    private :
        SimpleLCD *lcd;
    
    public:
        EmergencyTask(int myPeriod, State *currentState, SimpleLCD *lcd);
        void tick();
};

#endif