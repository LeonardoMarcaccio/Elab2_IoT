#ifndef _SERVO_
#define _SERVO_

#include "ActiveComponent.h"

class Servo : public ActiveComponent {
    public :
        virtual int getRotationDeg();
        virtual void setRotationDeg(int);
        virtual int getRotationSpeed();
        virtual void setRotationSpeed(float);
};

#endif
