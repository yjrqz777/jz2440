
#include "lcd.h"
#include "framebuffer.h"
#include "geometry.h"

void lcd_test2(void){
    lcd_init();
    lcd_enable();
    fb_get_lcd_params();


    DrawLine(0,0,100,100,0xff0000);


}









void lcd_test(void)
{
    unsigned int fb_base;
    int i;
    int xres;
    int yres;
    int bpp;
    int x, y;
    unsigned short *p;
    unsigned int *p2;
    lcd_init();
    lcd_enable();

    get_lcd_params(&fb_base,&xres,&yres,&bpp);
    fb_get_lcd_params();
    font_init();
    if(bpp == 16)
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

if(bpp == 32)
    {
        p2 = (unsigned int *)fb_base;
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {

                *p2++ = 0xff0000;
 
            }
        }
        p2 = (unsigned int *)fb_base;
        i=100000;
        while (--i);

        
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {
                *p2++ = 0xff;
            }
        }
        p2 = (unsigned int *)fb_base;
                i=100000;
        while (i--);
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {
                *p2++ = 0x00ff00;
            }
        }

        p2 = (unsigned int *)fb_base;
                i=100000;
        while (i--);
        for(y=0; y<yres; y++)
        {
            for(x=0; x<xres; x++)
            {
                *p2++ = 0;
            }
        }

    }

    DrawLine(0,0,xres,yres,0xff0000);
    DrawLine(xres,0,0,yres,0xff0000);


    DrawLine(0,0,xres,yres,0xff0000);
    DrawLine(0,0,xres,yres,0xff0000);

    draw_circle(xres/2,yres/2,100,0xff0000);

    fb_print_char(0,50,'a',0xff0000);
    fb_print_string(0,25,"abce\n\rwrwerg",0xff0000);
    fb_print_string(50,0,"abcde\rfgqwe",0xff0000);

}