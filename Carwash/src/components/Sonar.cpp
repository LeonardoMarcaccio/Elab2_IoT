#include <Arduino.h>
#include "Sonar.h"

Sonar::Sonar(int echoPin) {
    Sonar(triggerPin, echoPin, false);
}
Sonar::Sonar(int triggerPin, int echoPin) {
    Sonar(triggerPin, echoPin, false);
}
Sonar::Sonar(int triggerPin, int echoPin, bool powered) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->powered = powered;
}

bool Sonar::isPowered() {
    return powered;
}

void Sonar::setPowered(bool powered) {
    this->powered = powered;
}

double Sonar::getDetection() {
    return pulseIn(echoPin, HIGH) / 29 / 2;        // in cm
};
