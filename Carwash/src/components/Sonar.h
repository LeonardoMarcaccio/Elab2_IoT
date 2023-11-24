#ifndef _SONAR_
#define _SONAR_

#include "ActiveComponent.h"

class Sonar : public AnalogSensor {

    private :
        bool powered;
        int PINEcho;
        float maxDistance; //Non sono sicuro ritorni float

    public :
        Sonar(bool p, int pin);
        bool isPowered();
        void setPowered(bool powered);
        double getDetection();
};

#endif