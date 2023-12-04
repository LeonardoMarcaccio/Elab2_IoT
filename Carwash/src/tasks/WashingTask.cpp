#include <Arduino.h>
#include "State.h"
#include "WashingTask.h"
#include "../components/Thermometer.h"
#include "../components/Led.h"

WashingTask::WashingTask(int myPeriod, State *currentState, Thermometer *therm, Led *l2, unsigned long *washStart, unsigned long *emergencyStart, unsigned long *emergencyInterval) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->therm = therm;
    this->l2 = l2;
    this->MAXTEMP = 40;
    this->washStart = washStart;
    this->standardInterval = 5000; //  random
    this->interval = this->standardInterval;
    this->overheatInterval = 4000;
    this->emergencyStart = emergencyStart;
    this->emergencyInterval = emergencyInterval;
    this->emergencyFlag = false;
};

void WashingTask::tick() {

    State currentState = *(this->currentState);

    this->l2->setPowered(!this->l2->isPowered());

    if (this->emergencyFlag == true) {
        this->interval += *(this->emergencyInterval);
        this->emergencyFlag = false;
    }

    if ((currentState == WASH || currentState == OVERHEAT) &&
            millis() - *(this->washStart) >= this->interval) {
        *(this->currentState) = WASH_END;
        this->interval = this->standardInterval;
        return;
    }

    if (currentState == OVERHEAT &&
            millis() - this->overheatStart >= this->overheatInterval) {
        *(this->currentState) = EMERGENCY;
        *(this->emergencyStart) = millis();
        this->emergencyFlag = true;
    }

    if (currentState == WASH &&
            this->therm->getDetection() > this->MAXTEMP) {
        this->overheatStart = millis();
        *(this->currentState) = OVERHEAT;
    }

    if (currentState == OVERHEAT &&
            this->therm->getDetection() <= this->MAXTEMP) {
        *(this->currentState) = WASH;
    }
}