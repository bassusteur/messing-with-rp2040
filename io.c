#include "io.h"

// this is nothing i used in the end, i was trying to get things working using inline assembly not realizing how easy it was with C

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