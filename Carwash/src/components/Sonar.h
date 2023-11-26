#ifndef _SONAR_
#define _SONAR_

#include "AnalogSensor.h"

class Sonar : public AnalogSensor {

    private:
        bool powered;
        int distance;
        int triggerPin, echoPin;
    public:
        Sonar(int echoPin);
        Sonar(int triggerPin, int echoPin);
        Sonar(int triggerPin, int echoPin, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        double getDetection();
};

#endif
