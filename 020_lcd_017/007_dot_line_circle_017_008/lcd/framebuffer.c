

#include "lcd.h"
#include "framebuffer.h"

unsigned int fb_base;
int i;
int xres;
int yres;
int bpp;
void fb_get_lcd_params(void)
{
    get_lcd_params(&fb_base,&xres,&yres,&bpp);
}


unsigned short convert32bppto16bpp(unsigned int color)
{
    unsigned char r, g, b;
    unsigned short color16bpp;

    r = (color >> 16) & 0xff;
    g = (color >> 8) & 0xff;
    b = color & 0xff;

    color16bpp = ((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3);

    return color16bpp;
}




void fb_put_pixel(int x, int y, int color)
{
    unsigned char *pc;
    unsigned short *pw;
    unsigned int *pdw;

	unsigned int pixel_base = fb_base + (xres * bpp / 8) * y + x * bpp / 8;

	switch (bpp)
	{
		case 8:
			pc = (unsigned char *) pixel_base;
			*pc = color;
			break;
		case 16:
			pw = (unsigned short *) pixel_base;
			*pw = convert32bppto16bpp(color);
			break;
		case 32:
			pdw = (unsigned int *) pixel_base;
			*pdw = color;
			break;
	}
}

