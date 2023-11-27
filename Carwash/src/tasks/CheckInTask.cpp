#include "State.h"
#include "CheckInTask.h"
#include "../components/PIR.h"

CheckInTask::CheckInTask(int myPeriod, State *currentState, int *checkInTime, PIR *pir) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->checkInTime = checkInTime;
    this->pir = pir;
};

void CheckInTask::tick() {
    if(*(this->currentState) == AWAKE && this->pir->isDetecting() == true) {
        *(this->currentState) = CHECKIN;
        //  *(this->checkInTime) = timeFunc(); ??
    }
}