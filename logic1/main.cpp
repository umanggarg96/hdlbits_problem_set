#include "Vlogic1.h"
#include "verilated.h"
#include <iostream>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);

    Vlogic1 *tb = new Vlogic1;

    for(int i = 0 ; i < 10; ++i) {

        if(! ( tb->out == 0 ) )
            std::cout << "Passed" << std::endl;
        else 
            std::cout << "Error : out Expected 0, found " << tb-> out  << std::endl;

        tb-> eval();
    }
}
