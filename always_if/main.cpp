#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <cstdint>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop *tb = new Vtop;

    uint8_t counter;
    for(counter = 0; counter < (1 << 5); ++counter) {
        uint8_t a    = counter        & 0x01;
        uint8_t b    = (counter >> 1) & 0x01;
        uint8_t b1   = (counter >> 2) & 0x01;
        uint8_t b2   = (counter >> 3) & 0x01;

        uint8_t out  = (((b1 & b2) & 0x01)? b : a) & 0x01;

        tb -> a = a;
        tb -> b = b;
        tb -> sel_b1 = b1;
        tb -> sel_b2 = b2;

        tb -> eval();

        assert(tb -> out_assign == out);
        assert(tb -> out_always == out);

    }

    delete tb;
    return 0;
}
