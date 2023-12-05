#ifndef _STATE_
#define _STATE_

enum State {
    SLEEPING,
    AWAKE,
    OPEN_GATE,
    ENTERING,
    READY,
    WASH,
    OVERHEAT,
    EMERGENCY,
    WASH_END,
    CHECKOUT
};

#endif