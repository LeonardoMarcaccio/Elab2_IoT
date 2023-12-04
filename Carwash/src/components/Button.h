#ifndef __BUTTON__
#define __BUTTON__

#include "ActiveComponent.h"

//Class used to represent a Button object
class Button : public ActiveComponent {

    private:
        int pin;

    public:
        Button(int pin);
        bool isPowered();
        void setPowered(bool powered);

};

#endif