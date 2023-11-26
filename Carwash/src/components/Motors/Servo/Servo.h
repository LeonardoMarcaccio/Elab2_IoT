#ifndef _SERVO_
#define _SERVO_

#include "../../ActiveComponent.h"

class Servo : public ActiveComponent {
    private:
        int positivePin, negativePin, pwmPin;
        bool simpleUse = false;
        bool powered = false;
    public:
        Servo(int pwmPin);
        Servo(int positivePin, int negativePin, int pwmPin);
        Servo(int positivePin, int negativePin, int pwmPin, bool powered);
        bool isPowered();
        void setPowered(bool powered);
        int getRotationDeg();
        void setRotationDeg(int);
        int getRotationSpeed();
        void setRotationSpeed(float);
};

#endif
