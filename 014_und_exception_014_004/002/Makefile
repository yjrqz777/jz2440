all:  start.o led.o uart.o init.o main.o exception.o


	#arm-linux-ld -T start.o led.o uart.o init.o main.o -o sdram.elf 

	arm-linux-ld -T sdram.lds $^ -o sdram.elf 

	arm-linux-objcopy -O binary -S sdram.elf sdram.bin
	arm-linux-objdump -D sdram.elf > sdram.dis




clean:
	rm *.bin *.o *.elf *.dis




%.o:%.c
	arm-linux-gcc -c -o $@ $<
%.o : %.S
	arm-linux-gcc -c -o $@ $<
	
	