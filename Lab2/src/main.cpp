#include <iostream>
#include "DataProvider.h"
#include "SPI.h"
#include "ETH.h"
#include "UART.h"

using namespace std;
 
int main()
{
    DataProvider p;
    SPI s;
    ETH e;
    UART u;

    p.reg(&s);
    p.reg(&e);
    p.reg(&u);   
    p.broadcast(7);

    cout << "TEST"<<endl;

    return 0;
}