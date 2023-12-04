#ifndef _PIR_
#define _PIR_

#include "DigitalSensor.h"

//Class used to represent a Pir object
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
