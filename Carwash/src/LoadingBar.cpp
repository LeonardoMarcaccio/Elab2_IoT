#include <Arduino.h>
#include "LoadingBar.h"

#define BLOCK "A"

LoadingBar::LoadingBar(unsigned long start, unsigned long currentValue,
    unsigned long end, unsigned long barSize) {
    this->barSize = barSize;
    this->start = start;
    this->end = end;
    this->currentValue = currentValue;
    this->currentPercentage = calculatePercentage(this->start, this->currentValue, this->end);
    this->blockPercentage = 100 / this->barSize;
}

String LoadingBar::getLoadingBar() {
    String loadingBarString = "";
    unsigned long bars = this->currentPercentage / this->blockPercentage;
    for (unsigned long index = 0; index < bars; index++) {
        loadingBarString = loadingBarString + BLOCK;
    }
    return loadingBarString;
}

void LoadingBar::setCurrentValue(unsigned long currentValue) {
    this->currentValue = currentValue;
    /*Serial.print("CALCULATING PERC - ");
    Serial.print(start);
    Serial.print(" ");
    Serial.print(this->currentValue);
    Serial.print(" ");
    Serial.print(end);
    Serial.print(" - CALCULATING PERC\n");
    Serial.flush();*/
    this->currentPercentage = calculatePercentage(this->start, this->currentValue, this->end);
}

unsigned long LoadingBar::calculatePercentage(unsigned long start, unsigned long value, unsigned long end) {
    return (unsigned long)((double)(value-start)/(double)(end-start)*100); 
}

unsigned long LoadingBar::getPercentage() {
    return this->currentPercentage;
}