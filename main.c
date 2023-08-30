#include "main.h"


int main()
{
    stdio_init_all();

    // we define the gpio pin number
    uint32_t gpio = 25;

    // performs a left shift of the 1 of 25 positions (or whatever the gpio pin number is)
    uint32_t mask = 1 << gpio;

    // here you see me using the pico-sdk defined structs to write to the registers and setup our blinking led

    sio_hw->gpio_oe_clr = mask;
    sio_hw->gpio_clr = mask;
    gpio_set_function(gpio,GPIO_FUNC_SIO);
    sio_hw->gpio_oe_set = mask;

    while(true)
    {
        // the next function we execute will print the offset of the two members in the struct, 
        // this is important because it will show us that the size of the members (e.g 32 bit in our case) will define the offset between them
        // and is crucial when defining the location of the registers in memory
        printf("1: %i 2: %i\n", offsetof(sio_b_t,anything), offsetof(sio_b_t,anythingtwo)); // so here we take 

        sio_hw->gpio_set = mask;
        sleep_ms(200);
        sio_hw->gpio_clr = mask;
        sleep_ms(200);
    }
    return 0;

}
