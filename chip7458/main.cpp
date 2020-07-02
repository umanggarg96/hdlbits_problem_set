#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);
    bool pass = true;

    Vtop *tb = new Vtop;

    int counter;
    for(counter = 0 ; counter < (1 << 7); ++counter) { 
        
        // p1 logic check
        char p1a = counter        & 0x01;
        char p1b = (counter >> 1) & 0x01;
        char p1c = (counter >> 2) & 0x01;
        char p1d = (counter >> 3) & 0x01;
        char p1e = (counter >> 2) & 0x01;
        char p1f = (counter >> 3) & 0x01;
        
        tb-> p1a = p1a;
        tb-> p1b = p1b;
        tb-> p1c = p1c;
        tb-> p1d = p1d;
        tb-> p1e = p1e;
        tb-> p1f = p1f;

        char p1y = ( ( p1a & p1b & p1c ) | ( p1d & p1e & p1f ) ) & 0x01;

        // p2 logic check
        char p2a = counter        & 0x01;
        char p2b = (counter >> 1) & 0x01;
        char p2c = (counter >> 2) & 0x01;
        char p2d = (counter >> 3) & 0x01;
        
        tb-> p2a = p2a;
        tb-> p2b = p2b;
        tb-> p2c = p2c;
        tb-> p2d = p2d;

        char p2y = ( (p2a & p2b) | (p2c & p2d) ) & 0x01;


        tb-> eval();

        if(tb-> p1y !=  p1y) {
            pass = false;
            printf("Error : p1a = %1d, p1b = %1d, p1c = %1d, p1d = %1d, p1e = %1d, p1f = %1d,  p1y = %1d, Expected p1y = %1d\n", tb->p1a, tb->p1b, tb->p1c, tb->p1d, tb->p1e, tb->p1f, tb->p1y, p1y);
        }
        if(tb-> p2y !=  p2y) {
            pass = false;
            printf("Error : p2a = %1d, p2b = %1d, p2c = %1d, p2d = %1d, p2y = %1d, Expected p2y = %1d\n", tb->p2a, tb->p2b, tb->p2c, tb->p2d, tb->p2y, p2y);
        }

    }

    // TODO : add some random case

    if(pass) std::cout << "PASSED" << std::endl;

}
