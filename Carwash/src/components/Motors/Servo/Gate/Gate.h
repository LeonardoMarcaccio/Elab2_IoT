#ifndef _GATE_
#define _GATE_

#include "../Servo.h"

class Gate : public Servo {
    public :
        bool isOpen();
        void setOpen(bool);
};

#endif
