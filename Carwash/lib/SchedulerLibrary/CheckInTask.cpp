#include "Task.h"
#include "PinConfig.h"
#include "CheckInTask.h"
#include "components/PIR.h"

CheckInTask::CheckInTask(int myPeriod, int timeElapsed) :
    myPeriod(myPeriod),
    timeElapsed(timeElapsed),
    pir(PIR::PIR(true, PIN_PIR))
{};

void CheckInTask::Tick() {
    if(this->current == AWAKE && this->pir->isDetecting() == true) {
        this->currentState = CHECKIN;
    }
}