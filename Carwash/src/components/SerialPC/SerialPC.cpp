#include "SerialPC.h"
#include <Arduino.h>

void SerialPC::sendMessage(String data) {
    size_t bufSize = sizeof(char)*data.length();
    char* charBuf = (char*) malloc(bufSize);
    data.toCharArray(charBuf, bufSize, 0);
    Serial.write(charBuf);
}
// TODO: Finish this function
bool SerialPC::isConnected() {
    this->sendMessage("");
}
