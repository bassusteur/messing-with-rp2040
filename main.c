#include "main.h"


int main()
{
    stdio_init_all();
    uint32_t gpio = 25;
    uint32_t mask = 1 << gpio;

    sio_hw->gpio_oe_clr = mask;
    sio_hw->gpio_clr = mask;
    gpio_set_function(gpio,GPIO_FUNC_SIO);
    sio_hw->gpio_oe_set = mask;

    while(true)
    {
        printf("1: %i 2: %i\n", offsetof(sio_b_t,gpio_set), offsetof(sio_b_t,deez_nuts));
        sio_hw->gpio_set = mask;
        sleep_ms(200);
        sio_hw->gpio_clr = mask;
        sleep_ms(200);
    }
    return 0;

}
