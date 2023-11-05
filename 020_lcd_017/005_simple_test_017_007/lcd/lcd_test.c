
#include "lcd.h"


void lcd_test(void)
{
    unsigned int fb_base;
    int xres;
    int yres;
    int bpp;
    int x, y;
    unsigned short *p;
    lcd_init();
    lcd_enable();

    get_lcd_params(&fb_base,&xres,&yres,&bpp);
    if(bpp == 16)
    {
        p = (unsigned short *)fb_base;
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {
                *p++ = 0xf800;
            }
        }
    }
}