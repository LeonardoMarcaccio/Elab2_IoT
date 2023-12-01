#ifndef _SONAR_
#define _SONAR_

#include "AnalogSensor.h"

class Sonar : public AnalogSensor {

    private:
        bool powered;
        int pinTrig, pinEcho;
        float vs;
    public:
        Sonar(int pinTrig, int pinEcho);
        Sonar(int pinTrig, int pinEcho, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        double getDetection();
};

#endif
