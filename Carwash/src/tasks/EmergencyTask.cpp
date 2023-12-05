#include <Arduino.h>
#include "State.h"
#include "EmergencyTask.h"
#include "../components/SimpleLCD.h"
#include "../components/Button.h"
#include "../components/SerialPC/SerialPC.h"
#include "../components/SerialPC/SerialPCCommandFactory.h"
#include "../components/SerialPC/SerialCommandParser.h"
#include "../components/Constants.h"

EmergencyTask::EmergencyTask(int myPeriod, State *currentState, SerialPC *console, SimpleLCD *lcd, unsigned long *emergencyStart, unsigned long *emergencyInterval) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->console = console;
    this->lcd = lcd;
    this->emergencyStart = emergencyStart;
    this->emergencyInterval = emergencyInterval;
};

void EmergencyTask::tick() {
    if (*(this->currentState) == EMERGENCY) {
        this->console->sendMessage(SerialPCCommandFactory::dataPacket(SerialPCConstants::MC_PREFIX, SerialPCConstants::DATA, "Mantainance required"));
        this->lcd->clear();
        this->lcd->setDisplayText("Detected a problem", 0);
        this->lcd->setDisplayText("Please Wait", 1);
        if (SerialCommandParser::isManteinanceCompleteCommand(this->console->receiveMessage())) {
            *(this->currentState) = WASH;
            *(this->emergencyInterval) = millis() - *(this->emergencyStart);
            this->console->sendMessage("Mantainance done");
            this->lcd->clear();
        }
    }
}