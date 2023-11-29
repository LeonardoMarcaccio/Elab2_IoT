#ifndef __SERVOTASK__
#define __SERVOTASK__

#include "../SchedulerLibrary/Task.h"
#include "components/Motors/Servo/Servo.h"

class ServoTask: public Task {

    Servo *myservo;
    enum {UP = 500, DOWN = -500} gate;

    public:
        ServoTask(int pinServo);
        void init(int period);  
        void tick();
};

#endif