#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);
    bool pass = true;

    Vtop *tb = new Vtop;

    int counter;
    for(counter = 0 ; counter < (1 << 4); ++counter) { 
        char vec = counter   & 0x07;
        
        tb-> vec = vec;
        tb-> eval();

        if(tb-> outv !=  (vec & 0x07)) {
            pass = false;
            printf("Error : vec = %3d, outv = %3d, Expected outv = %3d\n", tb->vec, tb->outv, (vec & 0x07)); 
        }

        char o0 = vec        & 0x01;
        char o1 = (vec >> 1) & 0x01;
        char o2 = (vec >> 2) & 0x01;

        if(tb-> o0 !=  o0) {
            pass = false;
            printf("Error : vec = %3d, o0 = %1d, Expected o0 = %1d\n", tb->vec, tb->o0, o0); 
        }

        if(tb-> o1 !=  o1) {
            pass = false;
            printf("Error : vec = %3d, o1 = %1d, Expected o1 = %1d\n", tb->vec, tb->o1, o1); 
        }

        if(tb-> o2 !=  o2) {
            pass = false;
            printf("Error : vec = %3d, o2 = %1d, Expected o2 = %1d\n", tb->vec, tb->o2, o2); 
        }
    }

    // TODO : add some random case

    if(pass) std::cout << "PASSED" << std::endl;

}
