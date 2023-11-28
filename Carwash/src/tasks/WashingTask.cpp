#include <Arduino.h>
#include "State.h"
#include "WashingTask.h"

WashingTask::WashingTask(int myPeriod, State *currentState, unsigned long *washStartTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->washStartTime = washStartTime;
    this->interval = 0; //  random
    this->overheatInterval = 4000;
};

void WashingTask::tick() {

    State currentState = *(this->currentState);

    if ((currentState == WASH || currentState == OVERHEAT) &&
            millis() - *(this->washStartTime) >= this->interval) {
        *(this->currentState) = WASH_END;
        return;
    }

    if (currentState == OVERHEAT &&
            millis() - this->overheatStart >= this->overheatInterval) {
        *(this->currentState) = EMERGENCY;
    }

    if (/*  High Temperature && */
            currentState == WASH) {
        this->overheatStart = millis();
        *(this->currentState) = OVERHEAT;
    }

}