#ifndef UART_H
#define UART_H

#include "ICommBus.h"

class UART : public ICommBus {
public:                     
    void send(int n) override;
};

#endif