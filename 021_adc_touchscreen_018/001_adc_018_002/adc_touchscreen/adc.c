

#include "../s3c2440_soc.h"
#include "adc.h"

void adc_init(void)
{
/*

ECFLG [15] End of conversion flag(Read only)
0

PRSCEN [14] A/D converter prescaler enable
0

PRSCVL [13:6] A/D converter prescaler value
Data value: 0 ~ 255

0xFF

SEL_MUX [5:3] Analog input channel select
000 = AIN 0
001 = AIN 1
010 = AIN 2
011 = AIN 3
100 = YM
101 = YP
110 = XM
111 = XP
0

STDBM [2] Standby mode select
0 = Normal operation mode
1 = Standby mode
1

READ_ START [1] A/D conversion start by read
0 = Disable start by read operation
1 = Enable start by read operation
0


A/D conversion starts by enable.
If READ_START is enabled, this value is not valid.
0 = No operation
1 = A/D conversion starts and this bit is cleared after the startup.


*/

    ADCCON &= ~(7<<3);
    ADCCON = ((1<<14)|(49<<6));

    ADCDLY = 0x00ff;
}

int adc_read_ain0(void)
{

    ADCCON |= (1<<0);
    while(ADCCON & (1<<15));
    
    return ADCDAT0 &0x3ff;
    
}

