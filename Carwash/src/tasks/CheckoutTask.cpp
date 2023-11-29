#include <Arduino.h>
#include "State.h"
#include "CheckoutTask.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"

CheckoutTask::CheckoutTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Gate *gate) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->sonar = sonar;
    this->pir = pir;
    this->gate = gate;
    this->interval = 4000;
    this->dist = 10;
};

void CheckoutTask::tick() {

    State currentState = *(this->currentState);

    if (currentState == WASH_END) {
        this->gate->setOpen(true);

        if (!this->pir->isDetecting() && this->sonar->getDetection() >= this->dist) {
            *(this->currentState) = CHECKOUT;
            this->gate->setOpen(false);
            this->checkOutTime = millis();
        }
    }

    if (currentState == CHECKOUT &&
        millis() - this->checkOutTime >= this->interval) {
            *(this->currentState) = SLEEPING;
            interrupts();
    }
}