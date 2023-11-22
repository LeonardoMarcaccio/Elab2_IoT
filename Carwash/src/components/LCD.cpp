#include "Arduino.h"
#include "PinConfig.h"
#include "SimpleLCD.h"
#include <WString.h>

using namespace std;

class LCDImpl : public SimpleLCD {

    private :
        String text;
        int PIN;
    public :
        LCDImpl(String t, int pin) : text(t), PIN(pin) {}

        void setDisplayText(String text) {
            this->text = text;
        };

        String getDisplayText() {
            return this->text;
        };

        void clear() {

        };
};