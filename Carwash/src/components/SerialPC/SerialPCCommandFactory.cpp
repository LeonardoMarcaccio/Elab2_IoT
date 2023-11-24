#include <Arduino.h>
#include "SerialPCCommandFactory.h"
#include "../Constants.h"

String SerialPCCommandFactory::connectionMessage() {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::MC_PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::HANDSHAKE;
}

String SerialPCCommandFactory::dataPacket(String subject, String value) {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::MC_PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::DATA+SerialPCConstants::SPACING
        +subject+SerialPCConstants::SPACING+value;
}

String SerialPCCommandFactory::faultMessage(String subject) {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::MC_PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::FAULT+SerialPCConstants::SPACING+subject;
}

String SerialPCCommandFactory::connectionCheck() {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
        +SerialPCConstants::CONFIRM;
}