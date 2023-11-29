#ifndef _PIR_
#define _PIR_

#include "DigitalSensor.h"

class PIR : public DigitalSensor {
    private :
        int PIN;
        bool powered;
    public : 
        PIR(int pin, bool pwr);
        bool isPowered();
        void setPowered(bool pwr);
        bool isDetecting();
};

#endif
