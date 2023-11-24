#include "SerialPC.h"
#include <Arduino.h>

SerialPC::SerialPC() {
    this->pcCommandFactory = new SerialPCCommandFactory();
}
SerialPC::~SerialPC() {
    delete &this->pcCommandFactory;
}
void SerialPC::sendMessage(String data) {
    size_t bufSize = sizeof(char)*data.length();
    char* charBuf = (char*) malloc(bufSize);
    data.toCharArray(charBuf, bufSize, 0);
    Serial.write(charBuf);
}

bool SerialPC::isConnected() {
    this->sendMessage(this->pcCommandFactory->connectionCheck());
    String message = Serial.readString();
    return false;
}
