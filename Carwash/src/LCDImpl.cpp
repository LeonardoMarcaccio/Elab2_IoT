#include "Arduino.h"
#include "PinConfig.h"
#include "SimpleLCD.h"
#include <WString.h>

#include "Wire.h"
#include "LCD.h"
#include "LiquidCrystal_I2C.h"

using namespace std;

class LCDImpl : public SimpleLCD {

    private :
        String text;
        int PIN_1;
        int PIN_2;
    public :
        LCDImpl(String t, int pin_1, int pin_2) : text(t), PIN_1(pin_1), PIN_2(pin_2) {
            LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7);
            lcd.begin(16,2);
            lcd.setBacklightPin(3,POSITIVE);
            lcd.setBacklight(HIGH);
        }

        void setDisplayText(String text) {
            this->text = text;
            lcd.print(this->text);
        };

        String getDisplayText() {
            return this->text;
        };

        void clear() {
            this->setDisplayText("");
        };
};