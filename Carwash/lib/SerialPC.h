#ifndef _SERIALPC_
#define _SERIALPC_

#include "SerialListener.h"
#include <WString.h>

using namespace std;

class SerialPC {
    public:
        virtual void sendMessage(String);
        virtual void addListener(SerialListener);
        virtual void removeListener(SerialListener);
};

#endif
