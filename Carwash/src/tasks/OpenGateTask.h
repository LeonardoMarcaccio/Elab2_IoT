#ifndef __OPENGATETASK__
#define __OPENGATETASK__

#include "Task.h"
#include "../components/DistanceSensor.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"

class OpenGateTask : public Task {

    private :
        DistanceSensor *sonar;
        PIR *pir;
        Gate *gate;
        Led *l2;
        SimpleLCD *lcd;
        float MIN_DIST;
        bool flag;
    
    public:
        OpenGateTask(int myPeriod, State *currentState, DistanceSensor *sonar, PIR *pir, Gate *gate, Led *l2, SimpleLCD *lcd);
        void tick();
};

#endif