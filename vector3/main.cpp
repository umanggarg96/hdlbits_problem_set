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

    uint8_t  a,b,c,d,e,f;
    uint8_t  w,x,y,z;

    for(int i = 0 ; i < 10000; ++i) {
        a = rand() % 32;
        b = rand() % 32;
        c = rand() % 32;
        d = rand() % 32;
        e = rand() % 32;
        f = rand() % 32;

        
        // aaaaabbb_bbcccccd_ddddeeee_efffff11
        // wwwwwwww_xxxxxxxx_yyyyyyyy_zzzzzzzz

        z  =              0x03;
        z |= ( f << 2 ) & 0x7C;
        z |= ( e << 7 ) & 0x80;

        y  = ( e >> 1 ) & 0x0F;
        y |= ( d << 4 ) & 0xF0;

        x  = ( d >> 4 ) & 0x01;
        x |= ( c << 1 ) & 0x3E;
        x |= ( b << 6 ) & 0xC0;

        w  = ( b >> 2 ) & 0x07;
        w |= ( a << 3 ) & 0xF8;

        tb -> a = a;
        tb -> b = b;
        tb -> c = c;
        tb -> d = d;
        tb -> e = e;
        tb -> f = f;

        tb -> eval();

        if(tb -> w != w) {
            pass = false;
            printf("Error : a,b,c,d,e,f = %2x, %2x, %2x, %2x, %2x, %2x | w = %2x, expected w = %2x\n",tb->a, tb->b, tb->c, tb-> d, tb->e, tb->f, tb->w, w);
        }
        if(tb -> x != x) {
            pass = false;
            printf("Error : a,b,c,d,e,f = %2x, %2x, %2x, %2x, %2x, %2x | x = %2x, expected x = %2x\n",tb->a, tb->b, tb->c, tb-> d, tb->e, tb->f, tb->x, x);
        }
        if(tb -> y != y) {
            pass = false;
            printf("Error : a,b,c,d,e,f = %2x, %2x, %2x, %2x, %2x, %2x | y = %2x, expected y = %2x\n",tb->a, tb->b, tb->c, tb-> d, tb->e, tb->f, tb->y, y);
        }
        if(tb -> z != z) {
            pass = false;
            printf("Error : a,b,c,d,e,f = %2x, %2x, %2x, %2x, %2x, %2x | z = %2x, expected z = %2x\n",tb->a, tb->b, tb->c, tb-> d, tb->e, tb->f, tb->z, z);
        }

    }

    if(pass) std::cout << "PASSED" << std::endl;

    delete tb;
    return 0;

}
