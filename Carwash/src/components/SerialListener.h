#ifndef _SERVO_
#define _SERVO_

#include "SerialListener.h"

class SerialListener {
    /*private:
        void (*func)(char*[]);*/
    public:
        virtual void onMessageRecived();
};

#endif
