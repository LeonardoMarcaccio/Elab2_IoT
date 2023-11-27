#include "State.h"
#include "EmergencyTask.h"
#include "../components/SimpleLCD.h"

EmergencyTask::EmergencyTask(int myPeriod, State *currentState, SimpleLCD *lcd) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->lcd = lcd;
};

void EmergencyTask::tick() {
    if (*(this->currentState) == EMERGENCY) {
        lcd->setDisplayText("Detected a problem - Please Wait");
        if (false/*  Mantainance over  */) {
            *(this->currentState) = WASH;
        }
    }
}