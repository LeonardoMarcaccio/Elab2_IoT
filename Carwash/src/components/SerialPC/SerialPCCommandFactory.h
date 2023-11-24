#ifndef _SERIALPCCOMMANDFACTORY_
#define _SERIALPCCOMMANDFACTORY_

#include <Arduino.h>

class SerialPCCommandFactory {
    public:
        String connectionMessage();
        String dataPacket(String subject, String value);
        String faultMessage(String subject);
        String connectionCheck();
};

#endif
