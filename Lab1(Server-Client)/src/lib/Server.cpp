#include "server.h"
 
Server::Server()
{
}
 
Server::~Server()
{
}
 
Channel* Server::connect(int channelID)
{
    switch (channelID)
    {
        case SPEED:
            return &speedChannel;
        case TEMP:
            return &tempChannel;
        case RPM:
            return &rpmChannel;
        default:
            return nullptr;
    }
}
 
void Server::write(int channelID, ChannelData data)
{
    Channel* ch = connect(channelID);
    if (ch != nullptr)
    {
        ch->write(data);
    }
}