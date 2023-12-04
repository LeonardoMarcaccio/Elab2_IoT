#ifndef _ANALOGSENSOR_
#define _ANALOGSENSOR_

#include "ActiveComponent.h"

//Class used as a template for every component the needs to return an Analog signal
class AnalogSensor : public ActiveComponent {
    public :
        virtual double getDetection();
};

#endif
