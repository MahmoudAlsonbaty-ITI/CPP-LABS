#ifndef DataProvider_H
#define DataProvider_H

#include "ICommBus.h"
#include "bits/stdc++.h"

class DataProvider
{
    public:
    std::vector<ICommBus*> buses;

    void reg(ICommBus* bus);
    void broadcast(int n);

};
 
#endif