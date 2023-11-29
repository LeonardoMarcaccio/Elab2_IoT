#include <Arduino.h>
#include "State.h"
#include "OpenGateTask.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Servo.h"

OpenGateTask::OpenGateTask(int myPeriod, unsigned long *washStartTime, State *currentState, Sonar *sonar, PIR *pir, Servo *servo) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->sonar = sonar;
    this->pir = pir;
    this->servo = servo;
    this->washStartTime = washStartTime;
    this->MIN_DIST = 40;
    this->degree = 90;
};

void OpenGateTask::tick() {
    if (*(this->currentState) == OPEN_GATE) {
        this->servo->setRotationDeg(this->degree);

        if (this->sonar->getDetection() < this->MIN_DIST &&
            this->pir->isDetecting() == true) {
            *(this->currentState) = WASH;
            *(this->washStartTime) = millis();
            this->servo->setRotationDeg(0);
        }
    }
}