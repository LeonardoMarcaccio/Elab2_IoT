#include <Arduino.h>
#include "State.h"
#include "OpenGateTask.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"
#include "../components/Motors/Servo/Gate/Gate.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"

OpenGateTask::OpenGateTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir, Gate *gate, Led *l2, SimpleLCD *lcd) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->sonar = sonar;
    this->pir = pir;
    this->gate = gate;
    this->l2 = l2;
    this->lcd = lcd;
    this->flag = false;
    this->MIN_DIST = 5;
};

void OpenGateTask::tick() {
    if (*(this->currentState) == OPEN_GATE) {
        this->l2->setPowered(!this->l2->isPowered());
        //Serial.println("Blink : " + millis());

        if (!this->flag) {
            this->gate->setOpen(true);
            this->lcd->setDisplayText("Proceed to the Washing Area");
            this->flag = true;
        }

        if (this->sonar->getDetection() < this->MIN_DIST &&
            this->pir->isDetecting() == false) {
            *(this->currentState) = READY;
            this->gate->setOpen(false);
            this->lcd->setDisplayText("Ready to Wash");
            this->l2->setPowered(true);
            this->flag = false;
        }
    }
}
