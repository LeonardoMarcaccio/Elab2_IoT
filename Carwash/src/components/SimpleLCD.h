#ifndef _SIMPLELCD_
#define _SIMPLELCD_

#include "ActiveComponent.h"
#include <LiquidCrystal_I2C.h>

using namespace std;

class SimpleLCD : public ActiveComponent {

    private :
        String text;
        LiquidCrystal_I2C *lcd;

    public:
        SimpleLCD(String text);
        bool isPowered();
        void setPowered(bool pwr);
        void setDisplayText(String text);
        String getDisplayText();
        void clear();
};

#endif
