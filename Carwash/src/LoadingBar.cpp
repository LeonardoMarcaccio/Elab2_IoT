#include <Arduino.h>
#include "LoadingBar.h"

#define BLOCK "A"

LoadingBar::LoadingBar(uint8_t start, uint8_t currentValue,
    uint8_t end, uint8_t barSize) {
    this->barSize = barSize;
    this->start = start;
    this->end = end;
    this->currentValue = currentValue;
    this->currentPercentage = calculatePercentage(this->start, this->currentValue, this->end);
    this->blockPercentage = 100 / this->barSize;
}

String LoadingBar::getLoadingBar() {
    String loadingBarString = "";
    uint8_t bars = this->currentPercentage / this->blockPercentage;
    for (int index = 0; index < bars; index++) {
        loadingBarString = loadingBarString + BLOCK;
    }
    return loadingBarString;
}

void LoadingBar::setCurrentValue(uint8_t currentValue) {
    this->currentValue = currentValue;
    Serial.print("CALCULATING PERC - ");
    Serial.print(start);
    Serial.print(" ");
    Serial.print(this->currentValue);
    Serial.print(" ");
    Serial.print(end);
    Serial.print(" - CALCULATING PERC\n");
    Serial.flush();
    this->currentPercentage = calculatePercentage(this->start, this->currentValue, this->end);
}

uint8_t LoadingBar::calculatePercentage(uint8_t start, uint8_t value, uint8_t end) {
    return (uint8_t)((double)(value-start)/(double)(end-start)*100); 
}

uint8_t LoadingBar::getPercentage() {
    return this->currentPercentage;
}