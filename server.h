#ifndef SERVER_H
#define SERVER_H
 
#include "channel.h"
 
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
    Channel channels[NUM_OF_CHANNELS];
 
public:
    Server();
    ~Server();
 
    Channel* connect(int channelID);
    void write(int channelID, int data);
};
 
#endif
 