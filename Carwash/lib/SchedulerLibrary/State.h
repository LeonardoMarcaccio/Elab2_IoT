#ifndef _STATE_
#define _STATE_

enum State {
    SLEEPING,   //TASK: Awake
    AWAKE,      //TASK: DONE
    CHECKIN,    //TASK: Timer
    OPEN_GATE,  //TASK: TODO
    WASH,  //TASK: PIR Non detecta, Sonar in range
    OVERHEAT,   //TASK: Termometro
    EMERGENCY,  //TASK: Timer
    WASH_END,   //TASK: Open Gate 
    CHECKOUT    //TASK: PIR e Sonar Non detectano 
};

#endif