#ifndef _DISTANCESENSOR_
#define _DISTANCESENSOR_

#define MAX_PING_TIME 100000
#define DEFAULT_TEMP 20

#define DEBUG_DISTANCESENSOR

#include <Arduino.h>
#include "DigitalSensor.h"

//Class used to represent a Distance detector (A simple Sonar) object
class DistanceSensor : public DigitalSensor {
    private:
        uint8_t echoPin;
        uint8_t triggerPin;
        float readCache = 0.0f;
        bool powered;
    public:
        DistanceSensor(uint8_t echoPin, uint8_t triggerPin);
        DistanceSensor(uint8_t echoPin, uint8_t triggerPin, bool powered);
        float getDistance();
        bool isPowered();
        void setPowered(bool power);
        bool isDetecting();    
};

#endif
