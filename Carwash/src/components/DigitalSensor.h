#ifndef _DIGITALSENSOR_
#define _DIGITALSENSOR_

#include "ActiveComponent.h"

//Class used as a template for every component the needs to return an Digital signal
class DigitalSensor : public ActiveComponent {
    public :
        virtual bool isDetecting();
};

#endif
