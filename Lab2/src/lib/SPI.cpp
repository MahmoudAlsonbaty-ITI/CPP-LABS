#include "SPI.h"

#include <iostream>

    void SPI::send(int n){
        std::cout << "I'm the SPI and I got this! { " << n << " }"<<std::endl;
    }