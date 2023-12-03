#include <Arduino.h>
#include "DistanceSensor.h"

DistanceSensor::DistanceSensor(uint8_t echoPin, uint8_t triggerPin, bool powered) {
    this->echoPin = echoPin;
    this->triggerPin = triggerPin;
    this->powered = powered;
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}
DistanceSensor::DistanceSensor(uint8_t echoPin, uint8_t triggerPin)
    : DistanceSensor(echoPin, triggerPin, true) {}

bool DistanceSensor::isDetecting() {
    return this->powered;
}

void DistanceSensor::setPowered(bool powered) {
    this->powered = powered;
}

bool DistanceSensor::isPowered() {
    return this->powered;
}

float DistanceSensor::getDistance() {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    float vs = 331.45 + 0.62 * DEFAULT_TEMP;

    unsigned long duration = pulseIn(echoPin, HIGH, MAX_PING_TIME);

    if (duration == 0) {
        return this->readCache;
    }

    float t = duration / 1000.0 / 1000.0 / 2;

    #ifdef DEBUG_DISTANCESENSOR
        Serial.print("EchoPinNr: ");
        Serial.println(this->echoPin);
        Serial.print("TriggerPinNr: ");
        Serial.println(this->triggerPin);
        Serial.print("OpResult: ");
        Serial.println(t*vs);
        Serial.println("-----------");
        Serial.flush();
    #endif

    this->readCache = t*vs;

    return this->readCache;
}
