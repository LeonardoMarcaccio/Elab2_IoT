#include <Arduino.h>
#include "State.h"
#include "StartupTask.h"
#include "../components/PIR.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"

StartupTask::StartupTask(int myPeriod, State *currentState, PIR *pir, Led *l1, SimpleLCD *lcd, unsigned long *checkInTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->checkInTime = checkInTime;
    this->pir = pir;
    this->l1 = l1;
    this->lcd = lcd;
};

void StartupTask::tick() {
    if(*(this->currentState) == AWAKE) {
        noInterrupts();
        l1->setPowered(true);
        lcd->setDisplayText("Welcome");

        if (this->pir->isDetecting() == true) {
            *(this->currentState) = CHECKIN;
            *(this->checkInTime) = millis();
        }
    }
}