#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <cstdint>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);
    bool pass = true;

    Vtop *tb = new Vtop;

    uint16_t in_word;
    uint8_t  out_lo;
    uint8_t  out_hi;


    for(int i = 0 ; i < 2 ; ++i) {

        in_word = 0;
        do{

            out_lo = in_word        & 0x00FF;
            out_hi = (in_word >> 8) & 0x00FF;

            tb -> in = in_word;

            tb -> eval();

            if( tb-> out_lo != out_lo ) {
                pass = false;
                printf("Error : in = %4x, out_lo = %4x, out_hi = %4x, expected out_lo = %4x\n", tb-> in, tb-> out_lo, tb-> out_hi, out_lo);
            }

            if( tb-> out_hi != out_hi ) {
                pass = false;
                printf("Error : in = %4x, out_lo = %4x, out_hi = %4x, expected out_hi = %4x\n", tb-> in, tb-> out_lo, tb-> out_hi, out_hi);
            }
            ++in_word;
        } while(in_word != 0);
    }

    if(pass) std::cout << "PASSED" << std::endl;

    delete tb;
    return 0;

}
