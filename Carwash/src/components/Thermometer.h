#ifndef _THERMOMETER_
#define _THERMOMETER_

#include "AnalogSensor.h"

//Class used to represent a Thermometer object, using a Thermoresistor
class Thermometer : public AnalogSensor {

    private:
        bool powered;
        int pinThermometer, Vo;
        //Variables used to calculate the Temperature
        float R1 = 100000, logR2, R2, T, c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
    public:
        Thermometer(int pinThermometer);
        Thermometer(int pinThermometer, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        double getDetection();
};

#endif