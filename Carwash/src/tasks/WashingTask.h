#ifndef __WASHINGTASK__
#define __WASHINGTASK__

#include "Task.h"
#include "../components/Thermometer.h"

class WashingTask : public Task {

    private :
        Thermometer *therm;
        double MAXTEMP;
        unsigned long *washStart;
        unsigned long interval;
        unsigned long overheatStart;
        unsigned long overheatInterval;
        unsigned long standardInterval;
        unsigned long *emergencyStart;
        unsigned long *emergencyInterval;
        bool emergencyFlag;
    
    public:
        WashingTask(int myPeriod, State *currentState, Thermometer *therm, unsigned long *washStart, unsigned long *emergencyStart, unsigned long *emergencyInterval);
        void tick();
};

#endif