#ifndef CLIENT_H
#define CLIENT_H
 
#include "server.h"
 
class Client
{
public:
    Channel* ptr;
 
    Client(Server& server, int channelID);
 
    ChannelData read();
};
 
#endif