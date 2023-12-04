#include <Arduino.h>
#include <Servo.h>
#include "SimpleServo.h"

SimpleServo::SimpleServo(int pwmPin) {
    this->simpleUse = true;
    this->pwmPin = pwmPin;
    this->controlledServo.attach(this->pwmPin);
    pinMode(this->pwmPin, OUTPUT);
}
SimpleServo::SimpleServo(int positivePin, int negativePin, int pwmPin) {
    SimpleServo(positivePin, negativePin, pwmPin, true);
}
SimpleServo::SimpleServo(int positivePin, int negativePin, int pwmPin, bool powered) {
    this->positivePin = positivePin;
    this->negativePin = negativePin;
    this->pwmPin = pwmPin;

    pinMode(this->positivePin, OUTPUT);
    pinMode(this->negativePin, INPUT);
    pinMode(this->pwmPin, OUTPUT);

    digitalWrite(positivePin, powered ? HIGH : LOW);
}

bool SimpleServo::isPowered() {
    return this->powered;
}

void SimpleServo::setPowered(bool powered) {
    this->powered = simpleUse || powered;
    digitalWrite(positivePin, this->powered ? HIGH : LOW);
}

float SimpleServo::getRotationDeg() {
    return this->targetDeg;
}

void SimpleServo::setRotationDeg(int targetDeg) {
    Serial.println(this->pwmPin);
    Serial.println(targetDeg);
    this->targetDeg = targetDeg;
    this->controlledServo.write(targetDeg);
}
