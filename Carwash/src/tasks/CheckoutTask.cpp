#include <Arduino.h>
#include "State.h"
#include "CheckoutTask.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Servo.h"

CheckoutTask::CheckoutTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Servo *servo) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->pir = pir;
    this->degree = 90;
    this->interval = 4000;
    this->dist = 10;
};

void CheckoutTask::tick() {

    State currentState = *(this->currentState);

    if (currentState == WASH_END) {
        this->servo->setRotationDeg(this->degree);

        if (!this->pir->isDetecting() && this->sonar->getDetection() >= this->dist) {
            *(this->currentState) = CHECKOUT;
            this->servo->setRotationDeg(0);
            this->checkOutTime = millis();
        }
    }

    if (currentState == CHECKOUT &&
        millis() - this->checkOutTime >= this->interval) {
            *(this->currentState) = SLEEPING;
    }
}