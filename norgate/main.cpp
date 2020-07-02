#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);
    bool pass = true;

    Vtop *tb = new Vtop;

    if( ! ( tb -> out == 0 ) ) {
        std::cout << "Error : Expected out to be 0" << std::endl;
        pass = false;
    }

    int counter;
    for(counter = 0 ; counter < 8; ++counter) { 
        int a = counter        & 0x01;
        int b = (counter >> 1) & 0x01;
        
        tb-> a = a;
        tb-> b = b;
        tb-> eval();

        if(tb-> out !=  (!(a || b))) {
            pass = false;
            printf("Error : a = %1d, b = %1d, out = %1d, Expected out = %1d\n", tb->a, tb->b, tb->out, (!(a || b)));
        }

    }

    // TODO : add some random case

    if(pass) std::cout << "PASSED" << std::endl;

}
