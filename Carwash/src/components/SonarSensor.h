#ifndef _SONARSENSOR_
#define _SONARSENSOR_

class SonarSensor {
    private:
        int trig;
        int echo;
        bool powered;
    public:
        SonarSensor(int pinTrig, int pinEcho);
        SonarSensor(int pinTrig, int pinEcho, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        double getDetection();
};

#endif
