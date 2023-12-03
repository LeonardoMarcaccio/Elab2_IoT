#include <Arduino.h>
#include "SonarSensor.h"

SonarSensor::SonarSensor(int pinTrig, int pinEcho) {
    SonarSensor(pinTrig, pinEcho, true);
}

SonarSensor::SonarSensor(int pinTrig, int pinEcho, bool powered) {
    this->trig = pinTrig;
    this->echo = pinEcho;
    this->powered = powered;

    Serial.print(trig);
    Serial.print(" ");
    Serial.println(echo);
    Serial.print(this->trig);
    Serial.print(" ");
    Serial.println(this->echo);
}

bool SonarSensor::isPowered() {
    return powered;
}

void SonarSensor::setPowered(bool powered) {
    this->powered = powered;
}

double SonarSensor::getDetection() {
    digitalWrite(this->trig, LOW);
    delayMicroseconds(2);
  	digitalWrite(this->trig, HIGH);
  	delayMicroseconds(10);
  	digitalWrite(this->trig, LOW);

    Serial.print(this->trig);
    Serial.print(" ");
    Serial.println(this->echo);

  	double duration = pulseIn(this->echo, HIGH);
  	double distance = (duration*.0343)/2;
    return distance;
}
