#include "main.h"

int main()
{
    stdio_init_all();

    while(true)
    {
        int data = 0b0000001;
        //printf("test");
        printf("output of write: %#08x\n",write(data,REG_SIO_ADDR));
        sleep_ms(1000);
    }
    return 0;
}
