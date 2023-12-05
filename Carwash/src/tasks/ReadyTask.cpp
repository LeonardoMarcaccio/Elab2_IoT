#include <Arduino.h>
#include "State.h"
#include "ReadyTask.h"
#include "../components/SimpleLCD.h"
#include "../components/Button.h"

ReadyTask::ReadyTask(int myPeriod, State *currentState, SimpleLCD *lcd, Button *button, unsigned long *washStartTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->lcd = lcd;
    this->button = button;
    this->washStartTime = washStartTime;
};

void ReadyTask::tick() {
    if (*(this->currentState) == READY &&
            this->button->isPowered()) {
        *(this->currentState) = WASH;
        this->lcd->clear();
        *(this->washStartTime) = millis();
    }
    Serial.flush();
}