
#include "s3c2440_soc.h"
#include "uart.h"
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

        if(c=='\r')
            putchar('\n');
        if(c=='\n')
            putchar('\r');

        if(c=='1')
            open_led(1);
        if(c=='2')
            open_led(2);
        if(c=='3')
            open_led(3);
        putchar(c);

    }

    return 0;
}
