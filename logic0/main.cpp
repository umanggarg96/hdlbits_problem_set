#include "Vlogic0.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);

    Vlogic0 *tb = new Vlogic0;

    for(int i = 0 ; i < 10; ++i) {

        if(! ( tb->out == 1 ) )
            std::cout << "Passed" << std::endl;
        else 
            std::cout << "Error : out Expected 1, found " << tb-> out  << std::endl;

        tb-> eval();
    }
}
