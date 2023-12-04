#ifndef _STATE_
#define _STATE_

enum State {
    SLEEPING,   //TASK: Awake
    AWAKE,      //TASK: DONE
    OPEN_GATE,  //TASK: TODO
    ENTERING,
    READY,
    WASH,  //TASK: PIR Non detecta, Sonar in range
    OVERHEAT,   //TASK: Termometro
    EMERGENCY,  //TASK: Timer
    WASH_END,   //TASK: Open Gate 
    CHECKOUT    //TASK: PIR e Sonar Non detectano 
};

#endif