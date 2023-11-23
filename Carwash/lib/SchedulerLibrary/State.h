#ifndef _STATE_
#define _STATE_

enum State {
    SLEEPING,
    AWAKE,
    
    CHECKIN,
    OPEN_GATE,
    WASH_INIT,
    EMERGENCY,
    WASH_END,
    CHECKOUT
}

#endif