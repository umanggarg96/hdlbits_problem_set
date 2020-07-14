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

    int8_t  in;
    int32_t out;


    for(int j = 0; j < (1 << 9); ++j) {
        in = j;

        // calculate reverse of the var in
        
        out = in;

        tb -> in = in;
        tb -> eval();

        if(tb->out != out) {
            pass = false;
            printf("Error: in = %0d, out = %0d, expected out = %0d\n", tb->in, tb->out, out);
        }
    }

    if(pass) std::cout << "PASSED" << std::endl;

    delete tb;
    return 0;

}
