#ifndef _SERVO_
#define _SERVO_

#include "../../ActiveComponent.h"

class Servo : public ActiveComponent {
    private:
        int positivePin, negativePin, pwmPin;
        float targetDeg = 0;
        bool simpleUse = false;
        bool powered = false;
    public:
        Servo(int pwmPin);
        Servo(int positivePin, int negativePin, int pwmPin);
        Servo(int positivePin, int negativePin, int pwmPin, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        float getRotationDeg();
        void setRotationDeg(int targetDeg);
};

#endif
