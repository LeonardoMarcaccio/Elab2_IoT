#ifndef _SERVO_
#define _SERVO_

#include "SerialListener.h"

using namespace std;

class SerialListener {
    public :
        virtual void onMessageRecived();
};

#endif