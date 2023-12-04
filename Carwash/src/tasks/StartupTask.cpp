#include <Arduino.h>
#include "State.h"
#include "StartupTask.h"
#include "../components/PIR.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/Motors/Servo/Gate/Gate.h"

StartupTask::StartupTask(int myPeriod, State *currentState, PIR *pir, Gate *gate, Led *l1, SimpleLCD *lcd, unsigned long *checkInTime) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->awakeTime = millis();
    this->checkInTime = checkInTime;
    this->N1 = 3000;
    this->pir = pir;
    this->gate = gate;
    this->l1 = l1;
    this->lcd = lcd;
};

void StartupTask::tick() {
    if(*(this->currentState) == AWAKE) {
        this->l1->setPowered(true);
        this->lcd->setDisplayText("Welcome");

        if (millis() - this->awakeTime >= this->N1) {
            if (this->pir->isDetecting()) {
                this->gate->setOpen(true);
                this->lcd->setDisplayText("Proceed to the Washing Area");
                *(this->checkInTime) = millis();
                *(this->currentState) = OPEN_GATE;
            } else {
                this->lcd->clear();
                this->l1->setPowered(false);
                *(this->currentState) = SLEEPING;
            }
        }
    }
}