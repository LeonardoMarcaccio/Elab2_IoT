#include "Arduino.h"
#include "PinConfig.h"
#include "SimpleLCD.h"
#include <WString.h>

#include <LiquidCrystal_I2C.h>

using namespace std;

class LCDImpl : public SimpleLCD {

    private :
        String text;
        LiquidCrystal_I2C *lcd = new LiquidCrystal_I2C(0x27, 16, 2);
    public :
        LCDImpl(String t) : text(t) {
            lcd->init();
            lcd->backlight();
        }

        void setDisplayText(String text) {
            this->text = text;
            lcd->setCursor(0, 0);
            lcd->print(this->text);
        };

        String getDisplayText() {
            return this->text;
        };

        void clear() {
            lcd->clear();
        };
};