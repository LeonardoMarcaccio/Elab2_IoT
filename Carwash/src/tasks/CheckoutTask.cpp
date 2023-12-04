#include <Arduino.h>
#include "State.h"
#include "CheckoutTask.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/DistanceSensor.h"
#include "../components/Motors/Servo/Gate/Gate.h"

CheckoutTask::CheckoutTask(int myPeriod, State *currentState, DistanceSensor *sonar, Gate *gate, Led *l2, Led *l3, SimpleLCD *lcd) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->sonar = sonar;
    this->gate = gate;
    this->l2 = l2;
    this->l3 = l3;
    this->lcd = lcd;
    this->interval = 4000;
    this->dist = 0.1;
};

void CheckoutTask::tick() {

    State currentState = *(this->currentState);

    if (currentState == WASH_END) {
        this->gate->setOpen(true);
        this->l2->setPowered(false);
        this->l3->setPowered(true);
        this->lcd->setDisplayText("Washing complete, you can leave the area");

        if (this->sonar->getDistance() >= this->dist) {
            *(this->currentState) = CHECKOUT;
            this->checkOutTime = millis();
        }
    }

    if (currentState == CHECKOUT) {

        if (this->sonar->getDistance() < this->dist) {
            *(this->currentState) = WASH_END;
        }

        if(millis() - this->checkOutTime >= this->interval) {
            *(this->currentState) = SLEEPING;
            this->l3->setPowered(false);
            this->lcd->clear();
            this->gate->setOpen(false);
        }
    }
}