#include <Arduino.h>
#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include "SleepTask.h"
#include "State.h"
#include "../components/Led.h"

void awake() {}

SleepTask::SleepTask(int myPeriod, State *currentState, int interruptPin, Led *l1, Led *l2, Led *l3) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->interruptPin = interruptPin;
    this->l1 = l1;
    this->l2 = l2;
    this->l3 = l3;
}

void SleepTask::tick() {
    if (*(this->currentState) == SLEEPING) {
        enableInterrupt(this->interruptPin, awake, RISING);

        this->l1->setPowered(false);
        this->l2->setPowered(false);
        this->l3->setPowered(false);

        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_enable();
        sleep_mode();
        Serial.println("Welcome back!!!");
        sleep_disable();

        disableInterrupt(this->interruptPin);  
        *(this->currentState) = AWAKE;
    }
}