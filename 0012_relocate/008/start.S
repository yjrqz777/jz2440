.text
.global _start

_start:
    /*关闭看门狗*/

    ldr r0, =0x53000000
    ldr r1, =0x00000000
    str r1, [r0]
    /*设置MPLL FCLK:HCLK:PCLK= 400M: 100M: 50M*/

    ldr r0, =0x4c000000
    ldr R1, =0XFFFFFFFF
    str r1, [r0]

    /*CLKDIVN (0X4C000014)=0X5,tFCLK:tHCLK:tPCLK=1:4:8 */
    ldr r0, =0x4c000014
    ldr R1, =0X5
    str r1, [r0]
    /*设置cpu工作在异步模式*/
    mrc p15, 0, r0, c1, c0, 0
    orr r0, r0, #0xc0000000
    mcr p15, 0, r0, c1, c0, 0
    /*设置MPLLCON(0X4C000004)=(92<<12)| (1<<4)|(1<<0)*/
    ldr r0, =0X4C000004
    ldr R1, =(92<<12)| (1<<4)|(1<<0)
    str r1, [r0]


    /*设置内存SP栈*/
    mov r1, #0 /*写0到0地址*/
    ldr r0, [r1] /*读出原来的值备份*/
    str r1, [r1] /*0->[0]*/
    ldr r2, [r1] /*r2=[0]*/
    cmp r1, r2 /*r1==r2? 若果相等就是nand启动*/
    ldr sp, =0x40000000+4096 //nor flash启动
    moveq sp, #4096 /*nand 启动*/
    streq r0, [r1] /*恢复原来的值*/


    bl sdram_init

    //重定位text data rodata
    mov r1, #0
    ldr r2, =_start
    ldr r3, =__bss_start

cpy:
    ldr r4, [r1]
    str r4, [r2]
    add r1, r1, #4
    add r2, r2, #4
    cmp r2, r3
    ble cpy


    //清除bss段
    ldr r1, =__bss_start
    ldr r2, =_end
    mov r3, #0

clean:
    str r3, [r1]
    add r1, r1, #4
    cmp r1, r2
    ble clean

    //bl main     //使用BL相对跳转，程序任然在nor/sram执行
    ldr pc, =main   //使用LDR绝对跳转，程序在sdram执行
    
halt:
    b halt
