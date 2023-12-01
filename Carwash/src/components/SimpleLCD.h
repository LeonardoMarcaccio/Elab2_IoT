#ifndef _SIMPLELCD_
#define _SIMPLELCD_

#include "ActiveComponent.h"
#include <LiquidCrystal_I2C.h>

class SimpleLCD : public ActiveComponent {

    private :
        int address, rows, columns;
        String text;
        bool powered;
        LiquidCrystal_I2C *lcd;
    public:
        SimpleLCD(uint8_t address, uint8_t rows, uint8_t columns);
        bool isPowered();
        void setPowered(bool powered);
        void setDisplayText(String text);
        //void manualSetText(String text, uint8_t startrow, uint8_t startcolumn);
        String getDisplayText();
        void clear();
};

#endif
