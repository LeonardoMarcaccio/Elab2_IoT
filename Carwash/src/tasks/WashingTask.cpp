#include <Arduino.h>
#include "State.h"
#include "WashingTask.h"

WashingTask::WashingTask(int myPeriod, State *currentState, unsigned long *washStart, unsigned long *emergencyStart, unsigned long *emergencyInterval) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->washStart = washStart;
    this->interval = 0; //  random
    this->overheatInterval = 4000;
    this->emergencyStart = emergencyStart;
    this->emergencyInterval = emergencyInterval;
    this->emergencyFlag = false;
};

void WashingTask::tick() {

    State currentState = *(this->currentState);

    if (this->emergencyFlag == true) {
        this->emergencyIntervalCached += *(this->emergencyInterval);
        this->emergencyFlag = false;
    }

    if ((currentState == WASH || currentState == OVERHEAT) &&
            millis() - *(this->washStart) >= this->interval + this->emergencyIntervalCached) {
        *(this->currentState) = WASH_END;
        this->emergencyIntervalCached = 0;
        return;
    }

    if (currentState == OVERHEAT &&
            millis() - this->overheatStart >= this->overheatInterval) {
        *(this->currentState) = EMERGENCY;
        *(this->emergencyStart) = millis();
        this->emergencyFlag = true;
    }

    if (/*  High Temperature && */
            currentState == WASH) {
        this->overheatStart = millis();
        *(this->currentState) = OVERHEAT;
    }

}