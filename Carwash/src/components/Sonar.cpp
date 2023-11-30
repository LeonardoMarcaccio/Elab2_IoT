#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(int pinTrig, int pinEcho) {
    Sonar(pinTrig, pinEcho, false);
}
Sonar::Sonar(int triggerPin, int echoPin, bool powered) {
    this->pinTrig = triggerPin;
    this->pinEcho = echoPin;
    this->powered = powered;
    this->vs = 331.45 + 0.62 * 20;
}

bool Sonar::isPowered() {
    return powered;
}

void Sonar::setPowered(bool powered) {
    this->powered = powered;
}

double Sonar::getDetection() {
    digitalWrite(this->pinTrig,LOW);
    delayMicroseconds(3);
    digitalWrite(this->pinTrig,HIGH);
    delayMicroseconds(5);
    digitalWrite(this->pinTrig,LOW);

    /* Receiving the echo */

    float tUS = pulseIn(this->pinEcho, HIGH);
    float t = tUS / 1000.0 / 1000.0 / 2;
    return t*vs;
};
