#ifndef __PINGTASK__
#define __PINGTASK__

#include "..\SchedulerLibrary\Task.h"

class PingTask: public Task {

  int pinTrig;
  int pinEcho;

  public:

    PingTask(int pinTrig, int pinEcho);
    void init(int period);  
    void tick();
};

#endif