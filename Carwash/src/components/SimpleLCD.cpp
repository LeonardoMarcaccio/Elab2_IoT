#include <Arduino.h>
#include "PinConfig.h"
#include "SimpleLCD.h"
#include <LiquidCrystal_I2C.h>

//Implementation of the class SimpleLCD
SimpleLCD::SimpleLCD(uint8_t address, uint8_t rows, uint8_t columns) {
    this->address = address;
    this->rows = rows;
    this->columns = columns;
    this->lcd = new LiquidCrystal_I2C(address, rows, columns);
    this->lcd->init();
    this->lcd->backlight();
}

bool SimpleLCD::isPowered()  {
    return this->powered;
}

void SimpleLCD::setPowered(bool powered) {
    this->powered = powered;
    if (powered) {
        this->lcd->backlight();
    } else {
        this->lcd->noBacklight();
    }
}

void SimpleLCD::setDisplayText(String text, int row) {
    this->lcd->setCursor(0, row);
    this->lcd->print(text);
}

String SimpleLCD::getDisplayText() {
    return this->text;
}

void SimpleLCD::clear() {
    this->lcd->clear();
    this->text = "";
}