#ifndef __WASHINGTASK__
#define __WASHINGTASK__

#include "Task.h"
#include "../components/Motors/Servo/Servo.h"

class WashingTask : public Task {

    private :
        int degree;
        Servo *servo;
    
    public:
        WashingTask(int myPeriod, State *currentState, Servo *servo);
        void tick();
};

#endif