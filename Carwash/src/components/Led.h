#ifndef __LED__
#define __LED__

#include "ActiveComponent.h"

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