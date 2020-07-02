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
    for(counter = 0 ; counter < 32; ++counter) { 
        char a = counter        & 0x01;
        char b = (counter >> 1) & 0x01;
        char c = (counter >> 2) & 0x01;
        char d = (counter >> 3) & 0x01;
        
        tb-> a = a;
        tb-> b = b;
        tb-> c = c;
        tb-> d = d;
        tb-> eval();

        char out   = ( (a & b) | (c & d) ) & 0x01;
        char out_n = ( ~out ) & 0x01;
        if(tb-> out !=  out) {
            pass = false;
            printf("Error : a = %1d, b = %1d, out = %1d, Expected out = %1d\n", tb->a, tb->b, tb->out, out);
        }
        if(tb-> out_n !=  out_n) {
            pass = false;
            printf("Error : a = %1d, b = %1d, out = %1d, Expected out = %1d\n", tb->a, tb->b, tb->out_n, out_n);
        }

    }

    // TODO : add some random case

    if(pass) std::cout << "PASSED" << std::endl;

}
