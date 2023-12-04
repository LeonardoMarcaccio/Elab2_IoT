#ifndef _ACTIVECOMPONENT_
#define _ACTIVECOMPONENT_

//Class used to indicate every component that needs a power delivery from the Arduino
class ActiveComponent {
    public:
        virtual bool isPowered() = 0;
        virtual void setPowered(bool power) = 0;
        virtual ~ActiveComponent() = default;
};

#endif
