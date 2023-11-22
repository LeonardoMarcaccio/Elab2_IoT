#ifndef _SERVO_
#define _SERVO_

#include "SerialListener.h"

class SerialListener {
    public :
        virtual void onMessageRecived();
};

#endif
