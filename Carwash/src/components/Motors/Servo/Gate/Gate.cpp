#include "Gate.h"

// TODO: Finish constructors
Gate::Gate(int positivePin, int negativePin, int pwmPin, bool powered, int startingDeg, int endingDeg)
    : SimpleServo(positivePin, negativePin, pwmPin, powered){
    this->startingDeg = startingDeg;
    this->endingDeg = endingDeg;
}
Gate::Gate(int pwmPin, int startingDeg, int endingDeg) : SimpleServo(pwmPin) {
    this->startingDeg = startingDeg;
    this->endingDeg = endingDeg;
}

bool Gate::isOpen() {
    return this->open;
}

void Gate::setOpen(bool open) {
    this->open = open;
    if (this->open) {
        this->setRotationDeg(endingDeg);
    } else {
        this->setRotationDeg(startingDeg);
    }
}
