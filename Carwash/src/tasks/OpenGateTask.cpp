#include <Arduino.h>
#include "State.h"
#include "OpenGateTask.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"

OpenGateTask::OpenGateTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Gate *gate, unsigned long *washStartTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->sonar = sonar;
    this->pir = pir;
    this->gate = gate;
    this->washStartTime = washStartTime;
    this->MIN_DIST = 40;
};

void OpenGateTask::tick() {
    if (*(this->currentState) == OPEN_GATE) {
        this->gate->setOpen(true);

        if (this->sonar->getDetection() < this->MIN_DIST &&
            this->pir->isDetecting() == true) {
            *(this->currentState) = WASH;
            *(this->washStartTime) = millis();
            this->gate->setOpen(false);
        }
    }
}