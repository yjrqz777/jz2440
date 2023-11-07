
#include "adc.h"

#include "../uart.h"

void adc_test(void)
{
    adc_init();
    
    int val;
    double vol;
    char buf[64];
    int m,n;

	unsigned int fb_base;
	int xres, yres, bpp;
	int x, y;
	unsigned char *p0;
	unsigned short *p;
	unsigned int *p2;
		
	/* 初始化LCD */
	lcd_init();

	/* 使能LCD */
	lcd_enable();

	/* 获得LCD的参数: fb_base, xres, yres, bpp */
	get_lcd_params(&fb_base, &xres, &yres, &bpp);
	fb_get_lcd_params();
	font_init();
	
		p2 = (unsigned int *)fb_base;
		for (x = 0; x < xres; x++)
			for (y = 0; y < yres; y++)
				*p2++ = 0;
                unsigned int pixel_base = fb_base + (xres * bpp / 8) * 100 + 0 * bpp / 8;
                unsigned int pixel_base2 = fb_base + (xres * bpp / 8) * 116 + 0 * bpp / 8;
    while(1)
    {
        val = adc_read_ain0();
        vol = (double)val/1023.0*3.3;
        m=(int)vol;
        n=(int)((vol-m)*1000);
        Test_sprintf(buf, "val: %x, vol: %d.%03d\r\n", val, m,n);
        // printf("val: %x, vol: %d.%03d\r\n", val, m,n); 
        puts(buf);
        fb_print_string(10, 100, buf, 0xff);
        y=100000;
        while(--y);
        p2 = (unsigned int *)fb_base;
        unsigned int pixel_base = fb_base + (xres * bpp / 8) * 100 + 0 * bpp / 8;
		for (x = pixel_base; x <pixel_base2; x++)
				* (unsigned char *)pixel_base++ = 0xff;

    }
}
