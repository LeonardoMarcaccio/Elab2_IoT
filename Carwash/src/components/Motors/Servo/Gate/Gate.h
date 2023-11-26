#ifndef _GATE_
#define _GATE_

#include "../Servo.h"

class Gate : public Servo {
    private:
        int startingDeg, endingDeg;
        bool open;
    public:
        Gate(int pwmPin, int startingDeg, int endingDeg);
        Gate(int positivePin, int negativePin, int pwmPin, int startingDeg, int endingDeg);
        Gate(int positivePin, int negativePin, int pwmPin, bool powered, int startingDeg, int endingDeg);
        Gate(int startingDeg, int endingDeg);
        bool isOpen();
        void setOpen(bool open);
};

#endif
