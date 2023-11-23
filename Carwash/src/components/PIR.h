#ifndef _PIR_
#define _PIR_

#include "ActiveSensor.h"

class PIR : public DigitalSensor {
    private :
        bool powered;
        int PIN;
    public : 
        PIR(bool pwr, int pin);
};

#endif
