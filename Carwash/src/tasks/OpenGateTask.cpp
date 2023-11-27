#include "State.h"
#include "OpenGateTask.h"
#include "../components/Sonar.h"
#include "../components/PIR.h"

OpenGateTask::OpenGateTask(int myPeriod, State *currentState, Sonar *sonar, PIR *pir) {
    this->init(myPeriod);
    this->currentState = currentState;
    this->sonar = sonar;
    this->pir = pir;
};

void OpenGateTask::tick() {
    if(*(this->currentState) == OPEN_GATE       /* &&
            this->sonar->getDetection() < MIN_DIST &&
            this->pir->isDetecting() == true */ ) {
        *(this->currentState) = WASH;
    }
}