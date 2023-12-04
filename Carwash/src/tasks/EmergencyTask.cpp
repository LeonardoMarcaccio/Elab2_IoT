#include <Arduino.h>
#include "State.h"
#include "EmergencyTask.h"
#include "../components/SimpleLCD.h"
#include "../components/Button.h"
#include "../components/SerialPC/SerialPC.h"

EmergencyTask::EmergencyTask(int myPeriod, State *currentState, SerialPC *console, SimpleLCD *lcd, Button *button, unsigned long *emergencyStart, unsigned long *emergencyInterval) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->console = console;
    this->lcd = lcd;
    this->button = button;
    this->emergencyStart = emergencyStart;
    this->emergencyInterval = emergencyInterval;
};

void EmergencyTask::tick() {
    if (*(this->currentState) == EMERGENCY) {
        this->console->sendMessage("Mantainance required");
        this->lcd->setDisplayText("Detected a problem - Please Wait");
        if (this->button->isPowered()) {
            *(this->currentState) = WASH;
            *(this->emergencyInterval) = millis() - *(this->emergencyStart);
            this->console->sendMessage("Mantainance done");
            this->lcd->clear();
        }
    }
}