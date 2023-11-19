#ifndef _SERVO_
#define _SERVO_

#include "ActiveSensor.h"

using namespace std;

class ActiveSensor {
    public :
        virtual bool getDetectedState();
};

#endif