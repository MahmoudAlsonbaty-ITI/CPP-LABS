#ifndef SERVER_H
#define SERVER_H
 
#include "Channel.h"
 
enum ChannelID
{
    SPEED,
    TEMP,
    RPM,
    NUM_OF_CHANNELS
};
 
class Server
{
private:
    SpeedChannel speedChannel;
    TempChannel tempChannel;
    RpmChannel rpmChannel;
 
public:
    Server();
    ~Server();
 
    Channel* connect(int channelID);
    void write(int channelID, ChannelData data);
};
 
#endif