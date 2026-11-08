#include "server.h"
 
Server::Server()
{
    
}
 
Server::~Server()
{
}
 
Channel* Server::connect(int channelID)
{
    return &channels[channelID];
}
 
void Server::write(int channelID, int data)
{
    channels[channelID].write(data);
}
 