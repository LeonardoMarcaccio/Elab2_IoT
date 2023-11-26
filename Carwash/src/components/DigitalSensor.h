#ifndef _DIGITALSENSOR_
#define _DIGITALSENSOR_

#include "ActiveComponent.h"

class DigitalSensor : public ActiveComponent {
    public :
        DigitalSensor();
        virtual bool isDetecting();
};

#endif
