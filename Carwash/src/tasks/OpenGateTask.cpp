#include <Arduino.h>
#include "State.h"
#include "OpenGateTask.h"
#include "../components/DistanceSensor.h"
#include "../components/Motors/Servo/Gate/Gate.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"

OpenGateTask::OpenGateTask(int myPeriod, State *currentState, DistanceSensor *sonar, Gate *gate, Led *l2, SimpleLCD *lcd, unsigned long *checkInTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->checkInTime = checkInTime;
    this->N2 = 3000;
    this->sonar = sonar;
    this->gate = gate;
    this->l2 = l2;
    this->lcd = lcd;
    this->MIN_DIST = 0.05f;
}

void OpenGateTask::tick() {
    if (*(this->currentState) == OPEN_GATE) {
        this->l2->setPowered(!this->l2->isPowered());

        if (millis() - *(this->checkInTime) >= this->N2 &&
                this->sonar->getDistance() < this->MIN_DIST) {
            *(this->currentState) = READY;
            this->gate->setOpen(false);
            this->lcd->setDisplayText("Ready to Wash");
            this->l2->setPowered(true);
        }
    }
}
