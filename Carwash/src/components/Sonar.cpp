#include "Sonar.h"

Sonar::Sonar(bool p, int pin) {
    this->powered = p;
    this->PINEcho = pin;
}

bool Sonar::isPowered() {
    return powered;
}

void Sonar::setPowered(bool powered) {
    this->powered = powered;
}

double Sonar::getDetection() {
    return 0;
};