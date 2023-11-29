#include <Arduino.h>
#include "PinConfig.h"
#include "SimpleLCD.h"
#include <LiquidCrystal_I2C.h>

SimpleLCD::SimpleLCD(uint8_t address, uint8_t rows, uint8_t columns) {
    this->lcd = new LiquidCrystal_I2C(address, rows, columns);
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