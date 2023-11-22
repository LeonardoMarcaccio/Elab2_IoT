#ifndef _ACTIVECOMP_
#define _ACTIVECOMP_

class ActiveComponent {
public:
    virtual bool isPowered();
    virtual void setPowered(bool);
};

#endif
