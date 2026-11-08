#include "DataProvider.h"
 
// DataProvider::~DataProvider()
// {
// }
#include "bits/stdc++.h"

void DataProvider::broadcast(int n)
{
    for(auto t:buses){
        t->send(n);
    }
}
void DataProvider::reg(ICommBus* bus)
{
    buses.push_back(bus);
}
 
 