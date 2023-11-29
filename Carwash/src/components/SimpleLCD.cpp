#include "Arduino.h"
#include "PinConfig.h"
#include "SimpleLCD.h"
#include <LiquidCrystal_I2C.h>

SimpleLCD::SimpleLCD(String t) {
    this->text = t;
    this->lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    this->lcd->init();
    this->lcd->backlight();
}

bool SimpleLCD::isPowered()  {
    return true;
}

void SimpleLCD::setPowered(bool powered) {}

void SimpleLCD::setDisplayText(String text) {
    this->text = text;
    this->lcd->setCursor(0, 0);
    this->lcd->print(this->text);
}

String SimpleLCD::getDisplayText() {
    return this->text;
}

void SimpleLCD::clear() {
    this->lcd->clear();
}