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

void SimpleLCD::setDisplayText(String text) {
    this->clear();
    this->text = text;
    int lines = (text.length() % this->columns != 0)
        ? (text.length() / this->columns) + 1
        : text.length() / this->columns;

    int carouselA = 0, carouselB = this->columns;
    int remainingChars = text.length();
    
    for (int index = 0; index < lines; index++) {
        this->lcd->setCursor(0, index);
        this->lcd->print(text.substring(carouselA, carouselB));

       Serial.print("orcodeddio : " + text.substring(carouselA, carouselB));
       Serial.flush();

        carouselA = carouselA + this->columns;

        carouselB = (carouselB + this->columns) > remainingChars
                ? carouselB + remainingChars
                : carouselB + this->columns;

        remainingChars = (remainingChars >= this->columns) 
            ? remainingChars - this->columns
            : 0;
    }
}

String SimpleLCD::getDisplayText() {
    return this->text;
}

void SimpleLCD::clear() {
    this->lcd->clear();
    this->text = "";
}