#ifndef _SIMPLELCD_
#define _SIMPLELCD_

#include "ActiveComponent.h"

using namespace std;

class SimpleLCD : public ActiveComponent {
    public:
        virtual void setDisplayText(string);
        virtual string getDisplayText();
        virtual void clear();
};

#endif