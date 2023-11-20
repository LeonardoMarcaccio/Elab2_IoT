#include "Arduino.h"
#include "PinConfig.h"
#include "ActiveSensor.h"

#define CALIBRATION_TIME_SEC 5000

using namespace std;


class Pir : public DigitalSensor {

    private :
        bool powered;
        int PIN;

    public :
        Pir(bool p, int pin) : powered(p), PIN(pin) {
            //Serve????
            Serial.print("Calibrating sensor... ");
            for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
                Serial.print(".");
                delay(1000);
            }
            Serial.println(" done");
            Serial.println("PIR SENSOR READY.");
            delay(50);
        }
        
        bool isPowered() {
            return powered;
        };

        void setPowered(bool powered) {
            this->powered = powered;
        };

        bool isDetecting() {
            int detected = digitalRead(this->PIN);
            if (detected == HIGH){
                Serial.println("detected!");
                return true;
            }
            return false;
        };
};