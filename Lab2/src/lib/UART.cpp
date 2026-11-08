#include "UART.h"
#include <iostream>

    void UART::send(int n){
        std::cout << "I'm the UART and I got this! { " << n << " }"<<std::endl;
    }
