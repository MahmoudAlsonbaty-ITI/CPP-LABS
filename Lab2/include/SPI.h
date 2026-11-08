#ifndef SPI_H
#define SPI_H

#include "ICommBus.h"

class SPI : public ICommBus {
public:                     
    void send(int n) override;
};

#endif