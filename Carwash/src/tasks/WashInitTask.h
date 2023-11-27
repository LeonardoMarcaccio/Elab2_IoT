#ifndef __WASHINITTASK__
#define __WASHINITTASK__

#include "Task.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"

class WashInitTask : public Task {

    private :
        Sonar *sonar;
        PIR *pir;
    
    public:
        WashInitTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir);
        void tick();
};

#endif