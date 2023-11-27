#include "State.h"
#include "WashingTask.h"
#include "../components/Motors/Servo/Servo.h"

WashingTask::WashingTask(int myPeriod, State *currentState, Servo *servo) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->servo = servo;
    this->degree = 5;
};

void WashingTask::tick() {
    if (*(this->currentState) == OVERHEAT /*&& time*/) {
        *(this->currentState) = EMERGENCY;
    }

    if (*(this->currentState) == WASH ||
            *(this->currentState) == OVERHEAT) {
        this->servo->setRotationDeg(this->degree);
    }
}