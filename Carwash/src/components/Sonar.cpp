#include "Arduino.h"
#include "PinConfig.h"
#include "ActiveSensor.h"

class Sonar : public AnalogSensor {

    private :
        bool powered;
        int PINEcho;
        float maxDistance; //Non sono sicuro ritorni float

    public :
        Sonar(bool p, int pin) : powered(p), PINEcho(pin) {}
        
        bool isPowered() {
            return powered;
        };

        void setPowered(bool powered) {
            this->powered = powered;
        };

        double getDetection() {
            
        };
};