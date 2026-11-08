#include "Channel.h"
 
Channel::Channel()
{
    data = new int[100];
    readIndex = 0;
    writeIndex = 0;
}
 
Channel::~Channel()
{
    delete[] data;
}
 
void Channel::write(int d)
{
    data[writeIndex] = d;
    writeIndex = (writeIndex + 1) % 100;
}
 
int Channel::read()
{
    int d = data[readIndex];
    readIndex = (readIndex + 1) % 100;
    return d;
}
 