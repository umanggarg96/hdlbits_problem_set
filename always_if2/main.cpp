#include "Vtop.h"
#include "verilated.h"
#include <iostream>
#include <cstdio>
#include <cstdint>

int main(int argc, char ** argv) {
    Verilated::commandArgs(argc, argv);

    Vtop *tb = new Vtop;

    // TODO : easy. No need to test

    delete tb;
    return 0;
}
