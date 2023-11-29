#include <Arduino.h>
#include "State.h"
#include "StartupTask.h"
#include "../components/PIR.h"

StartupTask::StartupTask(int myPeriod, State *currentState, PIR *pir, unsigned long *checkInTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->checkInTime = checkInTime;
    this->pir = pir;
};

void StartupTask::tick() {
    if(*(this->currentState) == AWAKE && this->pir->isDetecting() == true) {
        noInterrupts();
        *(this->currentState) = CHECKIN;
        *(this->checkInTime) = millis();
    }
}