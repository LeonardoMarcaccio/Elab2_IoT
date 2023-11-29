#include <Arduino.h>
#include "State.h"
#include "CheckinTask.h"
#include "../components/PIR.h"

CheckinTask::CheckinTask(int myPeriod, State *currentState, PIR *pir, unsigned long *checkInTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->checkInTime = checkInTime;
    this->pir = pir;
    this->N1 = 4000;
};

void CheckinTask::tick() {
    if(*(this->currentState) == CHECKIN &&
            millis() - *(this->checkInTime) >= this->N1 &&
            this->pir->isDetecting() == true) {
        *(this->currentState) = OPEN_GATE;
    }
}