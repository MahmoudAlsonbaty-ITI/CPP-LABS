#ifndef ETH_H
#define ETH_H

#include "ICommBus.h"

class ETH : public ICommBus {
public:                     
    void send(int n) override;
};

#endif