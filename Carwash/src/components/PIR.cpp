#include "Arduino.h"
#include "PinConfig.h"
#include "ActiveSensor.h"
#include "Scheduler.h"

#define CALIBRATION_TIME_SEC 5000

using namespace std;

class PIR final : public DigitalSensor {

    private :
        bool powered;
        int PIN;
        Scheduler scheduler;

    public :
        PIR(bool p, unsigned int pin) : powered(p), PIN(pin) {
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
        PIR(Scheduler sheduler, bool p, int pin) : powered(p), PIN(pin) {
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
        
        bool isPowered() override {
            return powered;
        };

        void setPowered(bool powered) override {
            this->powered = powered;
        };

        bool isDetecting() override {
            int detected = digitalRead(this->PIN);
            if (detected == HIGH){
                Serial.println("detected!");
                return true;
            }
            return false;
        };
    ~PIR() {
        this->setPowered(false);
    }
};