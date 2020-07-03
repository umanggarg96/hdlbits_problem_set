#include "Vtop.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop *tb = new Vtop;

    if( ! ( tb -> out == 0 ) )
        std::cout << "Expected out to be 0" << std::endl;
    else
        std::cout << "Passed" << std::endl;

    tb -> in = 1;
    tb-> eval();

    if( ! ( tb -> out == 1 ) )
        std::cout << "Expected out to be 1" << std::endl;
    else
        std::cout << "Passed" << std::endl;

    tb -> in = 0;
    tb-> eval();

    if( ! ( tb -> out == 0 ) )
        std::cout << "Expected out to be 0" << std::endl;
    else
        std::cout << "Passed" << std::endl;

}
