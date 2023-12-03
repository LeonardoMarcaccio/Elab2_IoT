#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(int pinTrig, int pinEcho) {
    Sonar(pinTrig, pinEcho, true);
}
Sonar::Sonar(int pinTrig, int pinEcho, bool powered) {
    this->pinTrig = pinTrig;
    this->pinEcho = pinEcho;
    this->powered = powered;
    Serial.print(pinTrig);
    Serial.print(" ");
    Serial.println(pinEcho);
    Serial.print(this->pinTrig);
    Serial.print(" ");
    Serial.println(this->pinEcho);
    pinMode(this->pinTrig, OUTPUT);
    pinMode(this->pinEcho, INPUT);
}

bool Sonar::isPowered() {
    return powered;
}

void Sonar::setPowered(bool powered) {
    this->powered = powered;
}

double Sonar::getDetection() {
    digitalWrite(this->pinTrig, LOW);
    delayMicroseconds(2);
  	digitalWrite(this->pinTrig, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(this->pinTrig, LOW);
    Serial.print(this->pinTrig);
    Serial.print(" ");
    Serial.println(this->pinEcho);
  	double duration = pulseIn(this->pinEcho, HIGH);
  	double distance = (duration*.0343)/2;
    return distance;
};
