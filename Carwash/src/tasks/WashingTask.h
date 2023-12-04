#ifndef __WASHINGTASK__
#define __WASHINGTASK__

#include "Task.h"
#include "../components/Thermometer.h"
#include "../components/Led.h"
#include "../components/SimpleLCD.h"
#include "../components/SerialPC/SerialPC.h"
#include "../LoadingBar.h"

class WashingTask : public Task {

    private :
        Thermometer *therm;
        Led *l2;
        SimpleLCD *lcd;
        SerialPC *console;
        LoadingBar *progress;
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
        WashingTask(int myPeriod, State *currentState, Thermometer *therm, Led *l2, SimpleLCD *lcd, SerialPC *console, unsigned long *washStart, unsigned long *emergencyStart, unsigned long *emergencyInterval);
        void tick();
};

#endif