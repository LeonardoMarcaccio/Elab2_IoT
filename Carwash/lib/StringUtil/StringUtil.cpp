#include "StringUtil.h"
#include <Arduino.h>

String StringUtil::centerString(String stringToCenter, uint8_t charAmount, String offsetChar) {
    String stringOffset = "";
    int offset = round(stringToCenter.length() / 2);
    int half = round(charAmount / 2);
    int startingPosition = half - offset;
    for (int index = 0; index < startingPosition; index++) {
        stringOffset = stringOffset + offsetChar;
    }
    return (stringOffset + stringToCenter + stringOffset).substring(0, charAmount);
}
