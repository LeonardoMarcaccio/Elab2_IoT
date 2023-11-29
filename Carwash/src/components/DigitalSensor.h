#ifndef _DIGITALSENSOR_
#define _DIGITALSENSOR_

#include "ActiveComponent.h"

class DigitalSensor : public ActiveComponent {
    public :
        virtual bool isDetecting();
};

#endif
