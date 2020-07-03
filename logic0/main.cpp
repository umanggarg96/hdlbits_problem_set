#include "Vtop.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop *tb = new Vtop;

    for(int i = 0 ; i < 10; ++i) {

        if(! ( tb->out == 1 ) )
            std::cout << "Passed" << std::endl;
        else 
            std::cout << "Error : out Expected 1, found " << tb-> out  << std::endl;

        tb-> eval();
    }
}
