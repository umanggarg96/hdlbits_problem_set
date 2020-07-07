#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <cstdint>

int main(int argc, char ** argv) {

    Verilated::commandArgs(argc, argv);
    bool pass = true;

    Vtop *tb = new Vtop;

    uint32_t in_word;
    uint32_t out;


    for(uint32_t i = 0 ; i < 0xff ; ++i) {

        in_word = i;
        do{

            out =        (in_word << 24) & 0xFF000000;
            out = out | ((in_word << 8)  & 0x00FF0000);
            out = out | ((in_word >> 8)  & 0x0000FF00);
            out = out | ((in_word >> 24) & 0x000000FF);

            tb -> in = in_word;

            tb -> eval();

            if( tb-> out != out ) {
                pass = false;
                printf("Error : in = %8x, out = %8x, expected out = %8x\n", tb-> in, tb-> out, out);
            }

            in_word = in_word << 1;
        } while(in_word != 0);
    }


    // TODO : Add some random cases

    if(pass) std::cout << "PASSED" << std::endl;

    delete tb;
    return 0;

}
