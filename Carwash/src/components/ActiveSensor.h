#ifndef _SERVO_
#define _SERVO_

#include "ActiveComponent.h"

class DigitalSensor : public ActiveComponent {
    public :
        bool isDetecting();
        
};

class AnalogSensor {
    public :
        double getDetection();
};

#endif
