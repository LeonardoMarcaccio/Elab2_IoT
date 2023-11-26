#include "SerialPC.h"
#include <Arduino.h>
#include <ListLib.h>

SerialPC::SerialPC() {}
SerialPC::~SerialPC() {}

void SerialPC::sendMessage(String data) {
    size_t bufSize = sizeof(char)*data.length();
    char* charBuf = (char*) malloc(bufSize);
    data.toCharArray(charBuf, bufSize, 0);
    Serial.write(charBuf);
}

bool SerialPC::isConnected() {
    this->sendMessage(SerialPCCommandFactory::connectionCheck());
    String message = Serial.readString();
    return false;
}

void SerialPC::connect() {
    this->sendMessage(SerialPCCommandFactory::connectionMessage());
}

void SerialPC::addListener(SerialListener* listener) {
    
}
