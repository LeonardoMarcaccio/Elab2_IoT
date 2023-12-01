#include <Arduino.h>
#include "PinConfig.h"
#include "SimpleLCD.h"
#include <LiquidCrystal_I2C.h>

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
    Serial.println("Character length: ");
    Serial.flush();
    Serial.println(remainingChars);
    Serial.flush();
    Serial.print("Dividing string in: ");
    Serial.flush();
    Serial.println(lines);
    Serial.flush();
    for (int index = 0; index < lines; index++) {
        this->lcd->setCursor(0, index);
        this->lcd->print(text.substring(carouselA, carouselB));

        Serial.println("Appending: " + text.substring(carouselA, carouselB));
        Serial.flush();
        Serial.print("Printing carousels: ");
        Serial.flush();
        Serial.print(carouselA);
        Serial.flush();
        Serial.print(" ");
        Serial.flush();
        Serial.println(carouselB);
        Serial.flush();
        Serial.print("Cursor postion: ");
        Serial.flush();
        Serial.println(index);
        Serial.flush();
        // FIXME: This is horrible, too bad!
        carouselA = carouselA + this->columns;
        Serial.flush();
        Serial.print("*************************");
        Serial.flush();
        Serial.print(this->columns);
        Serial.flush();
        Serial.print(carouselA);

        carouselB = (carouselB + this->columns) > remainingChars
                ? carouselB + remainingChars
                : carouselB + this->columns;

        Serial.flush();
        Serial.print(carouselB);

        remainingChars = (remainingChars >= this->columns) 
            ? remainingChars - this->columns
            : 0;
    }
    //this->lcd->print(this->text);
}

/*void SimpleLCD::manualSetText(String text, uint8_t startrow, uint8_t startcolumn) {
    this->lcd->setCursor(startrow, startcolumn);
    this->lcd->write(text);
}*/

String SimpleLCD::getDisplayText() {
    return this->text;
}

void SimpleLCD::clear() {
    this->lcd->clear();
    this->text = "";
}