#include "main.h"

#define _CHEATER_(x) // so this macro is like _REG_(x) it actually does nothing and it's ignored by the compiler

// so if you look at "/hardware/address_mapped.h" you will see many typedef(s) these are for convenience's sake i believe and they define wether 
// the registers we're working with are read-only, write-only or both readable and writeable (hence rw, ro, wo)
typedef volatile uint32_t rw_32; // this is equal to io_rw_32

// here i recreate the typedef struct that's in "hardware/structs/sio.h"
typedef struct {
    _REG_(SIO_GPIO_OUT_SET_OFFSET) // again, this macro does nothing for the program it's only for IDE convenience as stated in "/hardware/address_mapped.h"
    rw_32 anything;    // this declares a member of the struct and uses the data type we defined which is 32 bits wide (4 bytes)
    rw_32 anythingtwo; // we declare another member here, will be important in main.c
} sio_b_t;

#define sio_b ((sio_b_t *)SIO_BASE) // this is a macro called sio_b, it contains a typecast of type sio_b_t with pointer at SIO_BASE
                                    // which tells the compiler to treat SIO_BASE as the memory address where the struct is located 
