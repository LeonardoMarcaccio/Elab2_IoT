#include <Arduino.h>
#include "../Constants.h"
#include "SerialCommandParser.h"
#include "SerialPCCommandFactory.h"

String SerialCommandParser::unencapsulateCommand(String command) {
    String msgStart = SerialPCCommandFactory::generateMessageHeading(SerialPCConstants::MC_PREFIX);
    if (command.startsWith(msgStart)) {
        command.remove(0, msgStart.length());
        return command;
    }
    return "";
}

bool SerialCommandParser::isManteinanceCompleteCommand(String command) {
    String unencapsulatedCommand = SerialCommandParser::unencapsulateCommand(command);
    if (command.equals(SerialPCCommandFactory::dataPacket(SerialPCConstants::PC_PREFIX, SerialPCConstants::TMP_SENSOR, SerialPCConstants::CONFIRM))) {
        return true;
    }
    return false;
}
