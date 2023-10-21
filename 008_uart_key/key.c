#include "s3c2440_soc.h"



#define Key1_Eint0 (GPGDAT & (1<<3))
#define Key2_Eint2 (GPFDAT & (1<<2))
#define Key3_Eint11 (GPFDAT & (1<<0))


#define led_1_ON (GPFDAT &= ~(1 << 4))
#define led_2_ON (GPFDAT &= ~(1 << 5))
#define led_3_ON (GPFDAT &= ~(1 << 6))
#define led_1_OFF (GPFDAT |= (1 << 4))
#define led_2_OFF (GPFDAT |= (1 << 5))
#define led_3_OFF (GPFDAT |= (1 << 6))
//EINT0:GPF0
//EINT2:GPF2
//EINT11:GPG3

int aaa = 0;



void delay_2(int d)
{
    while (d--)
        ;
}

void key_init()
{
    //清位
    GPFCON |= (3 << 0) | (3 << 4);
    GPGCON |= (3 << 6);
    //置位
    GPFCON &= ~(3 << 0) | (3 << 4);
    GPGCON &= ~(3 << 6);

}


void key_scan()
{
    unsigned int key_state_1 = 0;
    unsigned int key_state_2 = 0;
    unsigned int key_state_3 = 0;

    unsigned int key_state_last_1=0;
    unsigned int key_state_last_2=0;
    unsigned int key_state_last_3=0;

    int key_flag_1=0;
    int key_flag_2=0;
    int key_flag_3=0;


    key_state_last_1 = key_state_1;
    key_state_last_2 = key_state_2;
    key_state_last_3 = key_state_3;

    // if((!Key1_Eint0)){aaa=1;}
    // if(aaa==1){led_1_ON;}

    // if((Key1_Eint0))key_state_1=0;
    // if((!Key2_Eint2))led_1_OFF;
    // if((Key2_Eint2))key_state_2=0;
    // if(Key3_Eint11)key_state_3=0;
    // else key_state_3=1;


    key_state_1 = (!Key1_Eint0);
    key_state_2 = (!Key2_Eint2);
    key_state_3 = (!Key3_Eint11);

    if(key_state_1 && 1) key_flag_1=!key_flag_1;
    if(key_state_2 && 1) key_flag_2=!key_flag_2;
    if(key_state_3 && 1) key_flag_3=!key_flag_3;

    if(key_flag_1==1)led_1_ON;
    else led_1_OFF;
    if(key_flag_2==1)led_2_ON;
    else led_2_OFF;
    if(key_flag_3==1)led_3_ON;
    else led_3_OFF;

    // if(key_state_1)led_1_ON;
    // if(key_state_2)led_1_OFF;

    //按键按下时，引脚被拉低
    // if(key_flag_1 == 1)
    // {led_1_ON;
    //     key_flag_1=0;
    //     // return 1;
    // }
    // if(key_flag_2 == 1)
    // {led_2_ON;
    //     key_flag_2=0;
    //     // return 2;
    // }
    // if(key_flag_3 == 1)
    // {led_3_ON;
    //     key_flag_3=0;
    //     // return 3;
    // }
    // return 0;
}




