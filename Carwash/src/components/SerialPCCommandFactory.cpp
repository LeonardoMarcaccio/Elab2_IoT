#include <Arduino.h>
#include "SerialPCCommandFactory.h"
#include "Constants.h"

String SerialPCCommandFactory::connectionMessage() {
    return SerialPCConstants::PREFIX+SerialPCConstants::SPACING
    +SerialPCConstants::MC_PREFIX+SerialPCConstants::SPACING
    +SerialPCConstants::HANDSHAKE;
}
