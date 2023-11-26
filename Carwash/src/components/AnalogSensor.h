#ifndef _ANALOGSENSOR_
#define _ANALOGSENSOR_

#include "ActiveComponent.h"

class AnalogSensor : public ActiveComponent {
    public :
        virtual double getDetection();
};

#endif
