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

    uint8_t a, b;
    uint8_t out_or_bitwise, out_or_logical, out_not;

    uint8_t counter;

    for(counter = 0; counter < (1 << 7); ++counter) {
        a = counter        & 0x07;
        b = (counter >> 3) & 0x07;

        out_or_bitwise = (a | b);
        out_or_logical = a || b;
        out_not = ((~(b << 3)) & 0x38 ) | ( (~a) & 0x07);

        tb -> a = a;
        tb -> b = b;

        tb -> eval();

        assert(tb -> out_or_logical == out_or_logical);
        assert(tb -> out_or_bitwise == out_or_bitwise);
        assert(tb -> out_not == out_not);
        
    }

    if(pass) std::cout << "PASSED" << std::endl;

    delete tb;
    return 0;

}
