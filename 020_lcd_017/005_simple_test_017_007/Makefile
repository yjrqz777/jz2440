
obj = start.o led.o uart.o init.o nand_flash.o main.o exception.o interrupt.o timer.o nor_flash.o my_printf.o string_utils.o lib1funcs.o

objs += font.o
objs += framebuffer.o
objs += geometry.o
objs += lod_4.3.o
objs += lod.o
objs += lod_oontroller.o
objs += lod_test.o
objs += s3o2440_lod_oontroller.o




all: $(objs)
	#arm-linux-ld -Ttext 0 -Tdata 0x30000000  start.o led.o uart.o init.o main.o -o lcd.elf
	arm-linux-ld -T sdram.lds $^ -o lcd.elf
	arm-linux-objcopy -O binary -S lcd.elf lcd.bin
	arm-linux-objdump -D lcd.elf > lcd.dis
clean:
	rm *.bin *.o *.elf *.dis
	
%.o : %.c
	arm-linux-gcc -march=armv4 -c -o $@ $<

%.o : %.S
	arm-linux-gcc -march=armv4 -c -o $@ $<
	