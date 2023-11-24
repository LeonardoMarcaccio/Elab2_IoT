#ifndef __TASK__
#define __TASK__

#include "State.h"

class Task {
private:
  int myPeriod;
  int timeElapsed;

protected:
  State *currentState;
  
public:
  virtual void init(int period){
    myPeriod = period;  
    timeElapsed = 0;
  }

  virtual void tick();

  bool updateAndCheckTime(int basePeriod){
    timeElapsed += basePeriod;
    if (timeElapsed >= myPeriod){
      timeElapsed = 0;
      return true;
    } else {
      return false; 
    }
  }
  
};

#endif
