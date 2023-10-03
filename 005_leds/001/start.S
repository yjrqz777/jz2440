.text
.global _start

_start:
    /*关闭看门狗*/

    ldr r0, =0x53000000
    ldr r1, =0x00000000
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

    bl main

    
halt:
    b halt
