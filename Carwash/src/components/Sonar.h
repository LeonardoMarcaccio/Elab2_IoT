#ifndef _SONAR_
#define _SONAR_

class Sonar {
    private:
        int pinTrig = 0;
        int pinEcho = 0;
        bool powered = false;
    public:
        Sonar(int pinTrig, int pinEcho);
        Sonar(int pinTrig, int pinEcho, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        double getDetection();
};

#endif
