#ifndef __LED__
#define __LED__

#include "ActiveComponent.h"

//Class used to represent a Led object
class Led : public ActiveComponent { 
    private:
        int pin;
        bool powered;
    
    public:
        Led(int pin);
        bool isPowered();
        void setPowered(bool powered);
};

#endif