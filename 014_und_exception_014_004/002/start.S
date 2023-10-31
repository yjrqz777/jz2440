
.text
.global _start

_start:
	b reset  /* vector 0 : reset */
    ldr pc, =und_addr

und_addr:
    .word do_und


	//b do_und /* vector 4 : und */


do_und:
    //保存，处理，恢复,sp未设置
    ldr sp, =0x34000000
    stmdb sp!, {r0-r12, lr}

    mrs r0, cpsr
    ldr r1, =und_string
    bl printException


    //恢复
    ldmia sp!, {r0-r12, pc}^

und_string: 
	.string "undefined instruction exception"
	
.align 4

reset:
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

    bl copy2sdram

    //清除bss段

    bl clean_bss

    ldr pc, =sdram

sdram:
    bl uart0_init

    bl print1
und_code:
    .word 0xdeadc0de

    bl print2

    //bl main     //使用BL相对跳转，程序任然在nor/sram执行
    ldr pc, =main   //使用LDR绝对跳转，程序在sdram执行
    
halt:
    b halt
