#include "Client.h"
#include "server.h"
#include <iostream>
 
using namespace std;
 
int main()
{
    Server myServer;
    myServer.write(SPEED, 123);
    myServer.write(SPEED, 456);
 
    Client myClient(myServer, SPEED);
    Client myClient2(myServer, SPEED);
 
    cout << std::get<int>(myClient.read()) << endl;
    cout << std::get<int>(myClient2.read()) << endl;
 
    return 0;
}