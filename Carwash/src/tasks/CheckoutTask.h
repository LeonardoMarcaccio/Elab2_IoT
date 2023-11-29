#ifndef __CHECKOUTTASK__
#define __CHECKOUTTASK__

#include "Task.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Servo.h"

class CheckoutTask : public Task {

    private :
        unsigned long checkOutTime;
        unsigned long interval;
        double dist;
        int degree;
        Sonar *sonar;
        PIR *pir;
        Servo *servo;
    
    public:
        CheckoutTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Servo *servo);
        void tick();
};

#endif