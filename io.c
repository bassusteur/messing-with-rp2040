#include "io.h"

/*
void store(int data, int address, int offset)
{
    int out;
    asm(
        "ldr %%r0, %1;"
        "ldr %%r1, %2;"
        "ldr %%r2, %3;"
        "str %%r0, [%%r1, %%r2];"
        : "=r" (out)
        : "r" (data), "r" (address), "r" (offset)
        : "%r0", "%r1", "%r3"
       );
    
}
*/