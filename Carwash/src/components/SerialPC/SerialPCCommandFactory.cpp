#include <Arduino.h>
#include "SerialPCCommandFactory.h"
#include "../Constants.h"

String SerialPCCommandFactory::generateMessageHeading(String prefix) {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +prefix+SerialPCConstants::SPACING;
}

String SerialPCCommandFactory::connectionMessage() {
    return SerialPCCommandFactory::generateMessageHeading(SerialPCConstants::MC_PREFIX)
        +SerialPCConstants::HANDSHAKE
        +SerialPCConstants::ENDLINE;
}

String SerialPCCommandFactory::dataPacket(String prefix, String subject, String value) {
    return SerialPCCommandFactory::generateMessageHeading(prefix)
        +SerialPCConstants::DATA+SerialPCConstants::SPACING
        +subject+SerialPCConstants::SPACING+value
        +SerialPCConstants::ENDLINE;
}

String SerialPCCommandFactory::faultMessage(String subject) {
    return SerialPCCommandFactory::generateMessageHeading(SerialPCConstants::MC_PREFIX)
        +SerialPCConstants::FAULT+SerialPCConstants::SPACING
        +subject+SerialPCConstants::ENDLINE;
}

String SerialPCCommandFactory::connectionCheck() {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::CONFIRM
        +SerialPCConstants::ENDLINE;
}