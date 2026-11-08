#ifndef ICOMMBUS_H
#define ICOMMBUS_H
 
 
class ICommBus
{
public:
    virtual void send(int)=0;
    ~ICommBus()=default;
};
 
#endif