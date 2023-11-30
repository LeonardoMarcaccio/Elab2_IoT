#include <Arduino.h>
#include "State.h"
#include "EmergencyTask.h"
#include "../components/SimpleLCD.h"
#include "../components/Button.h"

EmergencyTask::EmergencyTask(int myPeriod, State *currentState, SimpleLCD *lcd, Button *button, unsigned long *emergencyStart, unsigned long *emergencyInterval) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->lcd = lcd;
    this->button = button;
    this->emergencyStart = emergencyStart;
    this->emergencyInterval = emergencyInterval;
};

void EmergencyTask::tick() {
    if (*(this->currentState) == EMERGENCY) {
        this->lcd->setDisplayText("Detected a problem - Please Wait");
        if (this->button->isPowered()) {
            *(this->currentState) = WASH;
            *(this->emergencyInterval) = millis() - *(this->emergencyStart);
            this->lcd->clear();
        }
    }
}