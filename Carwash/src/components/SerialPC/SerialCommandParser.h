#ifndef _SERIALCOMMANDPARSER_
#define _SERIALCOMMANDPARSER_

#include <Arduino.h>

class SerialCommandParser {
    private:
        static String unencapsulateCommand(String command);
    public:
        static bool isManteinanceCompleteCommand(String command);
};

#endif
