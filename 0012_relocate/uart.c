

#include "s3c2440_soc.h"

void uart0_init()
{
    // 设置引脚用于串口
    GPHCON &= ~((3 << 4) | (3<<6));   //  清零
    GPHCON |= ((2 << 4) | (2 << 6));    //  设置为TXD0，RXD0

    //上拉gph2,3     电阻

    GPHUP &= ~((1<<2)|(1<<3));

    //UBRDIVn = (int)( 50M(50 000 000) / ( 115200 x 16) ) –1= 26
    //  设置波特率
    UCON0 = 0x00000005; // 使能UART0中断，设置为查询模式
    UBRDIV0 = 26;   // 设置波特率为115200
    // 设置数据格式
    ULCON0 = 0x00000003;    // 8N1(8个数据位，无校验位，1个停止位)
    //  其他设置

}

int putchar(int c)
{
    // UTRSTAT0
    // UTXH0

    while (!(UTRSTAT0 & (1 << 2)))
        ;
    UTXH0 = (unsigned char)c;




}

int getchar(void)
{
    while (!(UTRSTAT0 & (1 << 0)))
        ;
    return URXH0;
}

int puts(const char *s)
{
    while (*s)
    {
        putchar(*s);
        s++;
    }
}

