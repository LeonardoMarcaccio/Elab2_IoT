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
    static const String ENDLINE = "\0";
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
    /**
     * Represents a problem on a specific component, should be followed by the component name.
    */
    static const String FAULT = "FAULT";
    /**
     * Represents a data packet, should be followed by some custom data and
     * a value separated by a spacer.
    */
    static const String DATA = "DATA";

    // COMPONENTS
    /**
     * Represents temperature sensor.
    */
    static const String TMP_SENSOR = "TMP";
    static const String WASH = "WASH";
};

#endif
