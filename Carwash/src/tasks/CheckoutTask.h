#ifndef __CHECKOUTTASK__
#define __CHECKOUTTASK__

#include "Task.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/DistanceSensor.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"

class CheckoutTask : public Task {

    private :
        unsigned long checkOutTime;
        unsigned long interval;
        double dist;
        DistanceSensor *sonar;
        PIR *pir;
        Gate *gate;
        Led *l2;
        Led *l3;
        SimpleLCD *lcd;
    
    public:
        CheckoutTask(int myPeriod, State *currentState, DistanceSensor *sonar, PIR *pir, Gate *gate, Led *l2, Led *l3, SimpleLCD *lcd);
        void tick();
};

#endif