#include "client.h"
 
Client::Client(Server& server, int channelID)
{
    ptr = server.connect(channelID);
}
 
int Client::read()
{
    return ptr->read();
}
 