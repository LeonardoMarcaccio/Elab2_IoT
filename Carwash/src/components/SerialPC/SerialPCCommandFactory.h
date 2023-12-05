#ifndef _SERIALPCCOMMANDFACTORY_
#define _SERIALPCCOMMANDFACTORY_

#include <Arduino.h>

//Factory Pattern fiero ahahahahah

class SerialPCCommandFactory {
    public:
        static String connectionMessage();
        static String dataPacket(String subject, String value);
        static String generateMessageHeading();
        static String faultMessage(String subject);
        static String connectionCheck();
};

#endif
