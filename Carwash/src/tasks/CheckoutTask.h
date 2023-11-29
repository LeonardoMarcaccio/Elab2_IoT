#ifndef __CHECKOUTTASK__
#define __CHECKOUTTASK__

#include "Task.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"

class CheckoutTask : public Task {

    private :
        unsigned long checkOutTime;
        unsigned long interval;
        double dist;
        Sonar *sonar;
        PIR *pir;
        Gate *gate;
    
    public:
        CheckoutTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Gate *gate);
        void tick();
};

#endif