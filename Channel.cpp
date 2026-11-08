#include "Channel.h"
 
Channel::~Channel()
{
}
 
SpeedChannel::SpeedChannel()
{
    data = new int[100];
    readIndex = 0;
    writeIndex = 0;
}
 
SpeedChannel::~SpeedChannel()
{
    delete[] data;
}
 
void SpeedChannel::write(ChannelData d)
{
    data[writeIndex] = std::get<int>(d);
    writeIndex = (writeIndex + 1) % 100;
}
 
ChannelData SpeedChannel::read()
{
    int d = data[readIndex];
    readIndex = (readIndex + 1) % 100;
    return d;
}
 
TempChannel::TempChannel()
{
    data = new double[100];
    readIndex = 0;
    writeIndex = 0;
}
 
TempChannel::~TempChannel()
{
    delete[] data;
}
 
void TempChannel::write(ChannelData d)
{
    data[writeIndex] = std::get<double>(d);
    writeIndex = (writeIndex + 1) % 100;
}
 
ChannelData TempChannel::read()
{
    double d = data[readIndex];
    readIndex = (readIndex + 1) % 100;
    return d;
}
 
RpmChannel::RpmChannel()
{
    data = new float[100];
    readIndex = 0;
    writeIndex = 0;
}
 
RpmChannel::~RpmChannel()
{
    delete[] data;
}
 
void RpmChannel::write(ChannelData d)
{
    data[writeIndex] = std::get<float>(d);
    writeIndex = (writeIndex + 1) % 100;
}
 
ChannelData RpmChannel::read()
{
    float d = data[readIndex];
    readIndex = (readIndex + 1) % 100;
    return d;
}