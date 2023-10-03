.text
.global _start

_start:



    //设置SP栈，配置启动方式（nand or nor）
    ldr sp, =4096 //nand flash启动

    //ldr sp, =0x40000000+4096 //nor flash启动

    mov r0, #4
    bl led_on

    ldr r0, =100000
    bl delay

    mov r0, #5
    bl led_on

    ldr r0, =100000
    bl delay
    
    
    //bl main
halt:
    b halt
