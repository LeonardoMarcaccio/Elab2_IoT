#ifndef __OPENGATETASK__
#define __OPENGATETASK__

#include "Task.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"

class OpenGateTask : public Task {

    private :
        Sonar *sonar;
        PIR *pir;
        Gate *gate;
        Led *l2;
        SimpleLCD *lcd;
        long MIN_DIST;
        bool flag;
    
    public:
        OpenGateTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Gate *gate, Led *l2, SimpleLCD *lcd);
        void tick();
};

#endif