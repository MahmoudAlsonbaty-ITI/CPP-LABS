#include "Client.h"
 
Client::Client(Server& server, int channelID)
{
    ptr = server.connect(channelID);
}
 
ChannelData Client::read()
{
    return ptr->read();
}