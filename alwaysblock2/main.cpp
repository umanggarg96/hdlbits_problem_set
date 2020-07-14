#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <cstdint>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop *tb = new Vtop;

    uint8_t out_ff = 0;
    uint8_t counter;
    for(counter = 0; counter < (1 << 3); ++counter) {
        uint8_t a = counter        & 0x01;
        uint8_t b = (counter >> 1) & 0x01;

        uint8_t out    = (a ^ b) & 0x01;

        tb -> a = a;
        tb -> b = b;

        tb -> eval();

        assert(tb -> out_always_comb == out);
        assert(tb -> out_assign      == out);

        // out_always_ff would not have changed with no clock
        assert(tb -> out_always_ff   == out_ff);


        tb -> clk = 0;
        tb -> eval();
        tb -> clk = 1;
        tb -> eval();

        assert(tb -> out_always_comb == out);
        assert(tb -> out_assign      == out);

        // out_always_ff would have changed
        assert(tb -> out_always_ff   == out);

        // update the value of ff mirror
        out_ff = out;
    }

    delete tb;
    return 0;
}
