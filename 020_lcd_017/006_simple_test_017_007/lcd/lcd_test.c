
#include "lcd.h"


void lcd_test(void)
{
    unsigned int fb_base;
    int i;
    int xres;
    int yres;
    int bpp;
    int x, y;
    unsigned short *p;
    lcd_init();
    lcd_enable();

    get_lcd_params(&fb_base,&xres,&yres,&bpp);
    while(bpp == 16)
    {
        p = (unsigned short *)fb_base;
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {
                if(y<90 && x<160)
                *p++ = 0xf800;
                else if(y<180 && x<320)
                *p++ = 0x7e0;
                else 
                *p++ = 0x1f;
            }
        }
        p = (unsigned short *)fb_base;
        i=1000000;
        while (--i);

        
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {
                *p++ = 0x7e0;
            }
        }
        p = (unsigned short *)fb_base;
                i=1000000;
        while (i--);
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {
                *p++ = 0x1f;
            }
        }
                i=1000000;
        while (i--);
        p = (unsigned short *)fb_base;
    }
}