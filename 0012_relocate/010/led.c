

#include "s3c2440_soc.h"

void delay(int d)
{
    while (d--)
        ;
}


void led_init()
{
    GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
    GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

    GPFDAT |= (7 << 4);

    delay(100000);
    GPFDAT &= ~(7<<4);
    delay(100000);
    GPFDAT |= (7 << 4);

}

int led_test()
{


    int val = 0;
    int temp;
     
    int i = 0;

    GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
    GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

    GPFDAT &= ~(7 << 4);

    while (i<10)
    {
        i++;
        temp = ~val;
        temp &= 7;
        GPFDAT &= ~(7 << 4);

        GPFDAT |= (temp << 4);
        delay(100000);
        val++;
        if (val == 8)
            val = 0;
    }

    return 0;
}


// void open_led(int led)
// {
//     if(led == 1)
//         GPFDAT &= ~(1 << 4);
//     if(led == 2)
//         GPFDAT &= ~(1 << 5);
//     if(led == 3)
//         GPFDAT &= ~(1 << 6);
//     delay(100000);
//     GPFDAT |= (7 << 4);
//     delay(100000);
// }
