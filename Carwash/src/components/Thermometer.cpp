#include <Arduino.h>
#include "Thermometer.h"

//Implementation of the class Thermometer
Thermometer::Thermometer(int pinThermometer) {
    Thermometer(pinThermometer, powered);
}

Thermometer::Thermometer(int pinThermometer, bool powered) {
    this->pinThermometer = pinThermometer;
    this->powered = powered;
}

bool Thermometer::isPowered() {
    return powered;
}

void Thermometer::setPowered(bool powered) {
    this->powered = powered;
}

double Thermometer::getDetection() {
    Vo = analogRead(this->pinThermometer);
    R2 = R1 * (1023.0 / (float)Vo - 1.0);
    logR2 = log(R2);
    T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
    return T - 273.15;
}