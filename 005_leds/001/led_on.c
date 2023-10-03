
void delay(int d)
{
    while (d--)
        ;
}

//     unsigned int *pGPFCON = (unsigned int *)0x56000050;
//     unsigned int *pGPFDAT = (unsigned int *)0x56000054;

// #define *pGPFCON (unsigned int *)0x56000050;

int led_on(int which)
{
    unsigned int *pGPFCON = (unsigned int *)0x56000050;
    unsigned int *pGPFDAT = (unsigned int *)0x56000054;

    if (which == 4)
    {
        *pGPFCON = 0x100;
    }
    else if (which == 5)
    {
        *pGPFCON = 0x400;
    }
    *pGPFDAT = 0;
}

int main()
{
    unsigned int *pGPFCON = (unsigned int *)0x56000050;
    unsigned int *pGPFDAT = (unsigned int *)0x56000054;

    int val = 0;
    int temp;

    *pGPFCON &= ~((3 << 8) | (3 << 10) | (3 << 12));
    *pGPFCON |= ((1 << 8) | (1 << 10) | (1 << 12));

    *pGPFDAT &= ~(7 << 4);

    while (1)
    {
        temp = ~val;
        temp &= 7;
        *pGPFDAT &= ~(7 << 4);

        *pGPFDAT |= (temp << 4);
        delay(100000);
        val++;
        if (val == 8)
            val = 0;
    }

    return 0;
}
