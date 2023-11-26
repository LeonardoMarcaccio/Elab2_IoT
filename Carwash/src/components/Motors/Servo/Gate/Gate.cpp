#include "Gate.h"

// TODO: Finish constructors
Gate::Gate(int positivePin, int negativePin, int pwmPin, bool powered, int startingDeg, int endingDeg)
    : Servo(positivePin, negativePin, pwmPin, powered){
    this->startingDeg = startingDeg;
    this->endingDeg = endingDeg;
}
Gate::Gate(int pwmPin, int startingDeg, int endingDeg) : Servo(pwmPin) {
    this->startingDeg = startingDeg;
    this->endingDeg = endingDeg;
}

bool Gate::isOpen() {
    return this->open;
}

void Gate::setOpen(bool open) {
    this->open = open;
}
