#include "Task.h"
#include "components/PIR.h"
#include "PinConfig.h"

class CheckInTask : public Task {
    private :
        
    public :
        CheckInTask(int myPeriod, int timeElapsed) : myPeriod(myPeriod), timeElapsed(timeElapsed) {
            
        };
        
};