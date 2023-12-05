#include <Arduino.h>
#include "../Constants.h"
#include "SerialCommandParser.h"
#include "SerialPCCommandFactory.h"

String SerialCommandParser::unencapsulateCommand(String command) {
    String msgStart = SerialPCCommandFactory::generateMessageHeading();
    if (command.startsWith(msgStart)) {
        command.remove(0, msgStart.length());
        return command;
    }
    return "";
}

bool SerialCommandParser::isManteinanceCompleteCommand(String command) {
    String unencapsulatedCommand = SerialCommandParser::unencapsulateCommand(command);
    if (command.equals(
        SerialPCCommandFactory::generateMessageHeading()
        + SerialPCCommandFactory::dataPacket(SerialPCConstants::DATA, SerialPCConstants::CONFIRM))) {
        return true;
    }
    return false;
}
