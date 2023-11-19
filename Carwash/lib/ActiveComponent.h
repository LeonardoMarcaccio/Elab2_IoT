#ifndef _ACTIVECOMP_
#define _ACTIVECOMP_

using namespace std;

class ActiveComponent {
public:
    virtual bool isPowered();
    virtual void setPowered(bool);
};

#endif