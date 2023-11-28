#ifndef __OPENGATETASK__
#define __OPENGATETASK__

#include "Task.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Servo.h"

class OpenGateTask : public Task {

    private :
        Sonar *sonar;
        PIR *pir;
        Servo *servo;
        unsigned long *washStartTime;
        long MIN_DIST;
        int degree;
    
    public:
        OpenGateTask(int myPeriod, unsigned long *washStartTime, State *currentState, Sonar *sonar, PIR *pir, Servo *servo);
        void tick();
};

#endif