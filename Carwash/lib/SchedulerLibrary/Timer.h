#ifndef __TIMER__
#define __TIMER__

class Timer {
    
public:  
  Timer();
  /**
   * Sets up a frequency for the timer given a time period
   * in ms.
   * @param freq the time period for every tick in ms
  */
  void setupFreq(int freq);  
  /* period in ms */
  void setupPeriod(int period);  
  void waitForNextTick();
};


#endif
