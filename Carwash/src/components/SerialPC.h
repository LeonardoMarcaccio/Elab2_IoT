#ifndef _SERIALPC_
#define _SERIALPC_

#include "SerialListener.h"

class SerialPC {
    private:
        
    public:
        void sendMessage(String);
        void addListener(SerialListener);
        void removeListener(SerialListener);
};

#endif
