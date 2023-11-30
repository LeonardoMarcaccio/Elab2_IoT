#ifndef _STRINGUTIL_
#define _STRINGUTIL_

#include <Arduino.h>

namespace StringUtil {
    String centerString(String stringToCenter, uint8_t charAmount, String offsetChar);
};

#endif
