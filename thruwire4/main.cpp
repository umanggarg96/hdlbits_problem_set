#include "Vthruwire4.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>

void check(Vthruwire4 *tb, bool w, bool x, bool y, bool z) {
    bool pass = true;
    if(tb-> w != w) { std::cout << "Error: w mismatch" << std::endl ; pass = false; }
    if(tb-> x != x) { std::cout << "Error: x mismatch" << std::endl ; pass = false; }
    if(tb-> y != y) { std::cout << "Error: y mismatch" << std::endl ; pass = false; }
    if(tb-> z != z) { std::cout << "Error: z mismatch" << std::endl ; pass = false; }
    if(pass) std::cout << "Passed" << std::endl;
}

int main(int argc, char ** argv) {
    
    Verilated::commandArgs(argc, argv);

    Vthruwire4 *tb = new Vthruwire4;

    check(tb, false, false, false, false);

    int counter;
    for(counter = 0; counter < 8; ++counter) {
        tb -> a = counter        & 0x01;
        tb -> b = (counter >> 1) & 0x01;
        tb -> c = (counter >> 2) & 0x01;

        tb -> eval();

        printf("Case %0d : %1d  | %1d | %1d\n", counter + 1, tb-> c, tb->b, tb->a);

        check(tb, tb->a, tb->b, tb->b, tb-> c);
    }
}

