#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);
    bool pass = true;

    Vtop *tb = new Vtop;

    uint8_t in;
    uint8_t out;


    for(unsigned int j = 0; j < (1 << 9); ++j) {
        in = j;

        // calculate reverse of the var in
        unsigned int i;
        out = in & 0x01;
        for(i = 1; i <= 7; ++i) {
            out <<= 1;
            out |= (in >> i) & 0x01;
        }

        tb -> in = in;

        tb -> eval();

        if(tb->out != out) {
            pass = false;
            printf("Error: in = %2x, out = %2x, expected out = %2x\n", tb->in, tb->out, out);
        }
    }

    if(pass) std::cout << "PASSED" << std::endl;

    delete tb;
    return 0;

}
