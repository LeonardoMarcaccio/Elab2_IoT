#ifndef __OPENGATETASK__
#define __OPENGATETASK__

#include "Task.h"
#include "../components/DistanceSensor.h"
#include "../components/Motors/Servo/Gate/Gate.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"

class OpenGateTask : public Task {

    private :
        unsigned long *checkInTime;
        unsigned long N2;
        DistanceSensor *sonar;
        Gate *gate;
        Led *l2;
        SimpleLCD *lcd;
        float MIN_DIST;
    
    public:
        OpenGateTask(int myPeriod, State *currentState, DistanceSensor *sonar, Gate *gate, Led *l2, SimpleLCD *lcd, unsigned long *checkInTime);
        void tick();
};

#endif