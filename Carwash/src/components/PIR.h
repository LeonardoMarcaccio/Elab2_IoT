#ifndef _PIR_
#define _PIR_

#include "DigitalSensor.h"

class PIR : public DigitalSensor {
    private :
        bool powered;
        int PIN;
    public : 
        PIR(bool pwr, int pin);
        bool isDetecting();
};

#endif
