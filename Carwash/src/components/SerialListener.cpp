#include <Arduino.h>
#include "SerialListener.h"
#include "SerialPCEvents.h"

SerialListener::SerialListener(void (*observerFunc)(SerialPCEvents, String)) {
    this->observerFunc = observerFunc;
}

void SerialListener::trigger(SerialPCEvents eventType, String message) {
    this->observerFunc(eventType, message);
}
