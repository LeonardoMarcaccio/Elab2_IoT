#ifndef _GATE_
#define _GATE_

#include "Servo.h"

using namespace std;

class Gate : public Servo {
    public :
        virtual bool isOpen();
        virtual void setOpen(bool);
};

#endif
