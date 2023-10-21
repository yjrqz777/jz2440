
#include "s3c2440_soc.h"
#include "uart.h"
#include "init.h"
#include "led.h"




int main()
{
    unsigned char c;
    volatile unsigned char *p = (volatile unsigned char *)0x30000000;
    uart0_init();
    led_init();

    sdram_init();

    if (sdram_test() == 0)
    {
        led_test();
    }
    else
    {
        puts("SDRAM test fail!\n\r");
    }


    puts("Hello, world!\n\r");



    while (1)
    {

        led_test();


    }

    return 0;
}
