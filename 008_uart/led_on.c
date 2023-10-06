

#include "s3c2440_soc.h"

void delay(int d)
{
    while (d--)
        ;
}


int led_test()
{


    int val = 0;
    int temp;

    GPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
    GPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

    GPFDAT &= ~(7 << 4);

    while (1)
    {
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
