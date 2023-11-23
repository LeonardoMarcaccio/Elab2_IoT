#ifndef _SERIALLISTENER_
#define _SERIALLISTENER_

#include <Arduino.h>
#include "SerialPCEvents.h"

class SerialListener {
    private:
        void (*observerFunc)(SerialPCEvents, String);
    public:
        SerialListener(void (*observerFunc)(SerialPCEvents, String));
        void trigger(SerialPCEvents eventType, String message);
};

#endif
