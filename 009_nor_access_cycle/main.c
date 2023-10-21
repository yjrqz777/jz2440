
#include "s3c2440_soc.h"
#include "uart.h"
#include "init.h"
#include "led.h"




int main()
{
    unsigned char c;
    uart0_init();
    led_init();
    puts("Hello, world!\n\r");



    while (1)
    {
        c = getchar();
        putchar(c);

        if(c>='0' && c<='7')   
        { 
        bank0_tacc_set(c-'0');
        led_test();
        }
        else
        {
            puts("Please input 0~7\n\r");
        }

    }

    return 0;
}
