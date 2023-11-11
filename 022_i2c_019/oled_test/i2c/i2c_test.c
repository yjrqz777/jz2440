
#include "oled.h"
#include "at24cxx.h"

void do_write_at24cxx(void)
{
	unsigned int addr;
	unsigned char str[100];
	int err;
	
	/* 获得地址 */
	printf("Enter the address of sector to write: ");
	addr = get_uint();

	if (addr > 256)
	{
		printf("address > 256, error!\n\r");
		return;
	}

	printf("Enter the string to write: ");
	gets(str);

	printf("writing ...\n\r");
	err = at24cxx_write(addr, str, strlen(str)+1);
	printf("at24cxx_write ret = %d\n\r", err);
}

// void oled_test()
// {
// 	at24cxx_write(,,8);
// }


void do_read_at24cxx(void)
{
	unsigned int addr;
	int i, j;
	unsigned char c;
	unsigned char data[100];
	unsigned char str[16];
	int len;
	int err=0;
	int cnt = 0;
	
	/* 获得地址 */
	printf("Enter the address to read: ");
	addr = get_uint();

	if (addr > 256)
	{
		printf("address > 256, error!\n\r");
		return;
	}

	/* 获得长度 */
	printf("Enter the length to read: ");
	len = get_int();
	printf("at24cxx_read ret = -----1-----%d-------------------\n\r", err);
	err = at24cxx_read(addr, data, len);

	printf("at24cxx_read ret = ----2-----%d-------------------\n\r", err);

	printf("Data : \n\r");
	/* 长度固定为64 */
	for (i = 0; i < 4; i++)
	{
		/* 每行打印16个数据 */
		for (j = 0; j < 16; j++)
		{
			/* 先打印数值 */
			c = data[cnt++];
			str[j] = c;
			printf("%02x ", c);
		}

		printf("   ; ");

		for (j = 0; j < 16; j++)
		{
			/* 后打印字符 */
			if (str[j] < 0x20 || str[j] > 0x7e)  /* 不可视字符 */
				putchar('.');
			else
				putchar(str[j]);
		}
		printf("\n\r");
	}
}

void test(void)
{


	oled_test();
	// int err=9999;
	// int addr;
	// OLED_Init();

	
	// printf("Enter the address to read: ");
	// addr = get_uint();
	// OLED_Clear(addr);
	// // err = at24cxx_cmd("0xaf");
	// printf("INIT = ---------%d-------------------\n\r", err);
}

void i2c_test(void)
{
	char c;

	/* 初始化 */
	i2c_init();

	while (1)
	{
		/* 打印菜单, 供我们选择测试内容 */
		printf("[w] Write at24cxx\n\r");
		printf("[r] Read at24cxx\n\r");
		printf("[V] oled_test\n\r");
		printf("[q] quit\n\r");
		printf("Enter selection: ");

		c = getchar();
		printf("%c\n\r", c);

		/* 测试内容:
		 * 3. 编写某个地址
		 * 4. 读某个地址
		 */
		switch (c)		 
		{
			case 'q':
			case 'Q':
				return;
				break;
				
			case 'w':
			case 'W':
				do_write_at24cxx();
				break;

			case 'r':
			case 'R':
				do_read_at24cxx();
				break;

			case 'v':
			case 'V':
				test();
				break;
			default:
				break;
		}
	}
}


