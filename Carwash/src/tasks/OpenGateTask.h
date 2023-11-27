#ifndef __OPENGATETASK__
#define __OPENGATETASK__

#include "Task.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"

class OpenGateTask : public Task {

    private :
        Sonar *sonar;
        PIR *pir;
    
    public:
        OpenGateTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir);
        void tick();
};

#endif