#include <Arduino.h>
#include "SerialPCCommandFactory.h"
#include "../Constants.h"

String SerialPCCommandFactory::connectionMessage() {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::MC_PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::HANDSHAKE
        +SerialPCConstants::ENDLINE;
}

String SerialPCCommandFactory::dataPacket(String subject, String value) {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::MC_PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::DATA+SerialPCConstants::SPACING
        +subject+SerialPCConstants::SPACING+value
        +SerialPCConstants::ENDLINE;
}

String SerialPCCommandFactory::faultMessage(String subject) {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::MC_PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::FAULT+SerialPCConstants::SPACING+subject
        +SerialPCConstants::ENDLINE;
}

String SerialPCCommandFactory::connectionCheck() {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::CONFIRM
        +SerialPCConstants::ENDLINE;
}