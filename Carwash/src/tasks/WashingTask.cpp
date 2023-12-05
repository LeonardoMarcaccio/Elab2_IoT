#include <Arduino.h>
#include "State.h"
#include "WashingTask.h"
#include "../components/Thermometer.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/SerialPC/SerialPC.h"
#include "../components/SerialPC/SerialPCCommandFactory.h"
#include "../components/Constants.h"
#include "../LoadingBar.h"

WashingTask::WashingTask(int myPeriod, State *currentState, Thermometer *therm, Led *l2, SimpleLCD *lcd, SerialPC *console, unsigned long *washStart, unsigned long *emergencyStart, unsigned long *emergencyInterval) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->therm = therm;
    this->l2 = l2;
    this->lcd = lcd;
    this->console = console;
    this->MAXTEMP = 40;
    this->washStart = washStart;
    this->standardInterval = 5000;
    this->interval = this->standardInterval;
    this->progress = new LoadingBar(0, 0, this->standardInterval, 20);
    this->overheatInterval = 4000;
    this->emergencyStart = emergencyStart;
    this->emergencyInterval = emergencyInterval;
    *(this->emergencyInterval) = 0;
    this->emergencyFlag = false;
};

void WashingTask::tick() {

    State currentState = *(this->currentState);
    double temp = this->therm->getDetection();
    unsigned long now = millis();

    if (this->emergencyFlag == true) {
        this->interval += *(this->emergencyInterval);
        this->emergencyFlag = false;
    }

    if (currentState == WASH || currentState == OVERHEAT) {
        unsigned long washStart = *(this->washStart);
        this->console->sendMessage(SerialPCCommandFactory::dataPacket(SerialPCConstants::MC_PREFIX, SerialPCConstants::TMP_SENSOR, String(temp)));
        this->l2->setPowered(!this->l2->isPowered());
        this->progress->setCurrentValue(now - washStart - *(this->emergencyInterval));
        this->lcd->clear();
        this->lcd->setDisplayText(this->progress->getLoadingBar(), 0);

        if (now - washStart >= this->interval) {
            *(this->currentState) = WASH_END;
            this->interval = this->standardInterval;
            *(this->emergencyInterval) = 0;
            return;
        }
    }

    if (currentState == OVERHEAT &&
            now - this->overheatStart >= this->overheatInterval) {
        *(this->currentState) = EMERGENCY;
        *(this->emergencyStart) = now;
        this->emergencyFlag = true;
    }

    if (currentState == WASH &&
            temp > this->MAXTEMP) {
        this->overheatStart = now;
        *(this->currentState) = OVERHEAT;
    }

    if (currentState == OVERHEAT &&
            temp <= this->MAXTEMP) {
        *(this->currentState) = WASH;
    }
}