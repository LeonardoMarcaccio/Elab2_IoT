#ifndef _SIMPLESERVO_
#define _SIMPLESERVO_

#include <PWMServo.h>
#include "../../ActiveComponent.h"

class SimpleServo : public ActiveComponent {
    private:
        PWMServo controlledServo;
        int positivePin, negativePin, pwmPin;
        float targetDeg = 0;
        bool simpleUse = false;
        bool powered = false;
    public:
        SimpleServo(int pwmPin);
        SimpleServo(int positivePin, int negativePin, int pwmPin);
        SimpleServo(int positivePin, int negativePin, int pwmPin, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        float getRotationDeg();
        void setRotationDeg(int targetDeg);
};

#endif
