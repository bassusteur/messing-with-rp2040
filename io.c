#include "io.h"

int write(int data, int address)
{
    int out=0;
    asm(
        "mov %%r1, %2;"
        "mov %%r2, %1;"
        //"str %%r2, [%%r1];"
        "mov %0, %%r1;"
        : "=r" (out)
        : "r" (data), "r" (address)
        : "%r1", "%r2"
       );
    
    return out;
}
