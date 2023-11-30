#include <Arduino.h>
#include "State.h"
#include "CheckoutTask.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"

CheckoutTask::CheckoutTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Gate *gate, Led *l2, Led *l3, SimpleLCD *lcd) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->sonar = sonar;
    this->pir = pir;
    this->gate = gate;
    this->l2 = l2;
    this->l3 = l3;
    this->lcd = lcd;
    this->interval = 4000;
    this->dist = 10;
};

void CheckoutTask::tick() {

    State currentState = *(this->currentState);

    if (currentState == WASH_END) {
        this->gate->setOpen(true);
        this->l2->setPowered(false);
        this->l3->setPowered(true);
        this->lcd->setDisplayText("Washing complete, you can leave the area");

        if (!this->pir->isDetecting() && this->sonar->getDetection() >= this->dist) {
            *(this->currentState) = CHECKOUT;
            this->gate->setOpen(false);
            this->checkOutTime = millis();
        }
    }

    if (currentState == CHECKOUT &&
        millis() - this->checkOutTime >= this->interval) {
            *(this->currentState) = SLEEPING;
            this->l3->setPowered(false);
            this->lcd->clear();
            interrupts();
    }
}