#ifndef _CONSTANTS_
#define _CONSTANTS_

#include <Arduino.h>

namespace SerialPCConstants {
    // STRUCTURE
    /**
     * Prefix to be used at the start of every message.
     * Only messages starting with this prefix should be considered.
    */
    static const String PREFIX = "CW";
    /**
     * Represents spacing to separate the various definitions.
    */
    static const String SPACING = "-";
    /**
     * Represents the prefix for the Microcontroller.
    */
    static const String MC_PREFIX = "MC";
    /**
     * Represents the prefix for che connected device.
    */
    static const String PC_PREFIX = "PC";

    // CONTROL
    static const String HANDSHAKE = "INIT";
    static const String CONFIRM = "ACK";
    static const String END = "CLOSE";

    // COMMANDS
    static const String FAULT = "FAULT";
    static const String DATA = "DATA";

    // DATA DESCRIPTORS
    static const String TMP = "TMP";
};

#endif
