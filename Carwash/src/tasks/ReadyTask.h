#ifndef __READYTASK__
#define __READYTASK__

#include "Task.h"
#include "../components/SimpleLCD.h"
#include "../components/Led.h"
#include "../components/Button.h"

class ReadyTask : public Task {

    private :
        unsigned long *washStartTime;
        SimpleLCD *lcd;
        Button *button;
    
    public:
        ReadyTask(int myPeriod, State *currentState, SimpleLCD *lcd, Button *button, unsigned long *washStartTime);
        void tick();
};

#endif