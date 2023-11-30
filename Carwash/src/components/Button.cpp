#include <Arduino.h>
#include "Button.h"

Button::Button(int pin) {
  this->pin = pin;
  this->powered = false;
  pinMode(pin, INPUT);
}

bool Button::isPowered() {
    return digitalRead(this->pin) == HIGH;
}

void Button::setPowered(bool powered) {}