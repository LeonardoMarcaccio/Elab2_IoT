#include <Arduino.h>
#include "Led.h"

//Implementation of the class Led
Led::Led(int pin) {
  this->pin = pin;
  this->powered = false;
  pinMode(pin, OUTPUT);
}

bool Led::isPowered() {
    return this->powered;
}

void Led::setPowered(bool powered) {
    this->powered = powered;
    if (this->powered) {
        digitalWrite(pin, HIGH);
    } else {
        digitalWrite(pin, LOW);
    }
}