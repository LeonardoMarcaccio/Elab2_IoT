#ifndef __BLINKTASK__
#define __BLINKTASK__

#include "../SchedulerLibrary/Task.h"

class BlinkTask: public Task {

  int pin;
  enum { ON, OFF} state;

public:

  BlinkTask(int pin);  
  void init(int period);  
  void tick();
};

#endif
