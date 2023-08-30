#include "main.h"

#define _CHEATER_(x)


typedef volatile uint32_t rw_32;

typedef struct {
    _REG_(SIO_GPIO_OUT_SET_OFFSET) // SIO_GPIO_OUT_SET
    io_wo_16 gpio_set;
    io_wo_16 deez_nuts;
} sio_b_t;

#define sio_b ((sio_b_t *)SIO_BASE)
