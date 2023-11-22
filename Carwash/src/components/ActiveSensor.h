#ifndef _SERVO_
#define _SERVO_

#include "ActiveComponent.h"

class DigitalSensor : public ActiveComponent {
    public :
        virtual bool isDetecting();
};

class AnalogSensor {
    public :
        virtual double getDetection();
};

#endif
