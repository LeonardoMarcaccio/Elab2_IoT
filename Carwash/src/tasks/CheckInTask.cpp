#include "State.h"
#include "CheckinTask.h"
#include "../components/PIR.h"

CheckinTask::CheckinTask(int myPeriod, State *currentState, int *checkInTime, PIR *pir) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->checkInTime = checkInTime;
    this->pir = pir;
};

void CheckinTask::tick() {
    if(*(this->currentState) == CHECKIN /* &&
            timeFunc() - *(this->checkInTime) >= N1 &&
            this->pir->isDetecting() == true */ ) {
        *(this->currentState) = OPEN_GATE;
    }
}