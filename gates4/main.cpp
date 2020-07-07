#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <cstdint>
#include <cassert>

int main(int argc, char ** argv) {

    Verilated::commandArgs(argc, argv);
    bool pass = true;

    Vtop *tb = new Vtop;

    uint8_t in;
    uint8_t out_and, out_or, out_xor;

    uint8_t counter;
    uint8_t bit;


    for(counter = 1; counter < (1 << 5); ++counter) {
        in = counter & 0x0F;


        out_and = in & 0x01;
        out_or  = in & 0x01;
        out_xor = in & 0x01;

        for(int i = 1; i < 4; ++i) {
            bit = (in >> i) & 0x01;

            out_and &= bit;
            out_or  |= bit;
            out_xor ^= bit;
        }

        tb->in = in;

        tb -> eval();

        assert(tb -> out_and == out_and);
        assert(tb -> out_or  == out_or );
        assert(tb -> out_xor == out_xor);
        
    }

    if(pass) std::cout << "PASSED" << std::endl;

    delete tb;
    return 0;

}
