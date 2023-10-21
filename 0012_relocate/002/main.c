
#include "s3c2440_soc.h"
#include "uart.h"
#include "init.h"
#include "led.h"


char g_char ='A';
// const char g_char2 = 'B';

// int g_A = 0;
// int g_B;


int main()
{
    
    uart0_init();
    puts("Hello, world!\n\r");
    // putchar(g_char);
    while (1)
    {

        putchar(g_char);
        g_char++;   //nor flash中存放的代码，不可能修改，所以这里的g_char是不会变的
        delay(1000000);


    }

    return 0;
}
