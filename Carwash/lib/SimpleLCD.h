#ifndef _SIMPLELCD_
#define _SIMPLELCD_

#include "ActiveComponent.h"
#include <WString.h>

using namespace std;

class SimpleLCD : public ActiveComponent {
    public:
        virtual void setDisplayText(String);
        virtual String getDisplayText();
        virtual void clear();
};

#endif
