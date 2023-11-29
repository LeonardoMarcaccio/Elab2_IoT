#ifndef _ACTIVECOMPONENT_
#define _ACTIVECOMPONENT_

class ActiveComponent {
    public:
        virtual bool isPowered() = 0;
        virtual void setPowered(bool power) = 0;
};

#endif
