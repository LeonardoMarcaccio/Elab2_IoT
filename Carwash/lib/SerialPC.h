#ifndef _SERIALPC_
#define _SERIALPC_

#include "SerialListener.h"
#include <string.h>

using namespace std;

class SerialPC {
    public:
        virtual void sendMessage(string);
        virtual void addListener(SerialListener);
        virtual void removeListener(SerialListener);
};

#endif