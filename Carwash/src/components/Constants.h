#ifndef _CONSTANTS_
#define _CONSTANTS_

#include <Arduino.h>

namespace SerialPCConstants {
    // STRUCTURE
    /**         * Prefix to be used at the start of every message.
     * Only messages starting with this prefix should be considered.
    */
    static const String PREFIX = "CW";
    static const String SPACING = "-";
    static const String MC_PREFIX = "MC";
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
