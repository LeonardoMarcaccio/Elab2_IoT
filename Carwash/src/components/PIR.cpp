#include "Arduino.h"
#include "PinConfig.h"
#include "DigitalSensor.h"
#include "Scheduler.h"
#include "PIR.h"

#define CALIBRATION_TIME_SEC 3

//Implementation of the class Pir
PIR::PIR(int pin, bool p) : PIN(pin), powered(p) {
    //Calibration period
    Serial.print("Calibrating sensor... ");
    for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
        Serial.print(".");
        //delay(100);
    }
    Serial.println(" done");
    Serial.println("PIR SENSOR READY.");
    //delay(50);
}


bool PIR::isPowered()  {
    return powered;
}

void PIR::setPowered(bool powered) {
    this->powered = powered;
}

bool PIR::isDetecting() {
    int detected = digitalRead(this->PIN);
    if (detected == HIGH){
        Serial.println("detected!");
        return true;
    }
    return false;
}