#ifndef __CHECKOUTTASK__
#define __CHECKOUTTASK__

#include "Task.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/DistanceSensor.h"
#include "../components/Motors/Servo/Gate/Gate.h"
#include "../components/SerialPC/SerialPC.h"

class CheckoutTask : public Task {

    private :
        unsigned long checkOutTime;
        unsigned long interval;
        uint8_t washCount;
        double dist;
        DistanceSensor *sonar;
        Gate *gate;
        Led *l2;
        Led *l3;
        SimpleLCD *lcd;
        SerialPC *console;
    
    public:
        CheckoutTask(int myPeriod, State *currentState, DistanceSensor *sonar, Gate *gate, Led *l2, Led *l3, SimpleLCD *lcd, SerialPC *console);
        void tick();
};

#endif