#include <Arduino.h>
#include "Servo.h"

Servo::Servo(int pwmPin) {
    this->simpleUse = true;
    this->pwmPin = pwmPin;

    pinMode(this->pwmPin, OUTPUT);
}
Servo::Servo(int positivePin, int negativePin, int pwmPin) {
    Servo(positivePin, negativePin, pwmPin, true);
}
Servo::Servo(int positivePin, int negativePin, int pwmPin, bool powered) {
    this->positivePin = positivePin;
    this->negativePin = negativePin;
    this->pwmPin = pwmPin;

    pinMode(this->positivePin, OUTPUT);
    pinMode(this->negativePin, INPUT);
    pinMode(this->pwmPin, OUTPUT);

    digitalWrite(positivePin, powered ? HIGH : LOW);
}

bool Servo::isPowered() {
    return this->powered;
}

void Servo::setPowered(bool powered) {
    this->powered = simpleUse || powered;
    digitalWrite(positivePin, this->powered ? HIGH : LOW);
}

float Servo::getRotationDeg() {
    return this->targetDeg;
}

void Servo::setRotationDeg(int targetDeg) {
    this->targetDeg = targetDeg;
    analogWrite(this->pwmPin, map(targetDeg, 0, 180, 0, 180));
}
