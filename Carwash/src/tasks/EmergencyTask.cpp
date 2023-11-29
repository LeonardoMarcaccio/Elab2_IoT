#include <Arduino.h>
#include "State.h"
#include "EmergencyTask.h"
#include "../components/SimpleLCD.h"

EmergencyTask::EmergencyTask(int myPeriod, State *currentState, SimpleLCD *lcd, unsigned long *emergencyStart, unsigned long *emergencyInterval) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->lcd = lcd;
    this->emergencyStart = emergencyStart;
    this->emergencyInterval = emergencyInterval;
};

void EmergencyTask::tick() {
    if (*(this->currentState) == EMERGENCY) {
        lcd->setDisplayText("Detected a problem - Please Wait");
        if (false/*  Mantainance over  */) {
            *(this->currentState) = WASH;
            *(this->emergencyInterval) = millis() - *(this->emergencyStart);
        }
    }
}