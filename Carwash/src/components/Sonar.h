#ifndef _SONAR_
#define _SONAR_

#include "AnalogSensor.h"

class Sonar : public AnalogSensor {

    private :
        bool powered;                                       // TODO: RIMUOVI
        int PINEcho;                                        // TODO: RIMUOVI
        float maxDistance; //Non sono sicuro ritorni float  // TODO: RIMUOVI

    public :
        Sonar(bool p, int pin);
        bool isPowered();
        void setPowered(bool powered);
        double getDetection();
};

#endif