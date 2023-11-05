
#include "lcd.h"

lcd_params lcd_4_3_params={
    .name=  "lcd_4.3",
    .pins_pol= {
        .vclk = NORMAL,
        .rgb = NORMAL,
        .hsync = NORMAL,
        .vsync = NORMAL,
        .de = NORMAL,
        .pwren = NORMAL,

    },
    .time_seq = {
        .tvp = 10,
        .tvb = 2,
        .tvf = 2,
        .thp = 41,
        .thb = 2,
        .thf = 2,  
        .vclk = 9,
    },
    .xres = 480,
    .yres = 272,
    .bpp = 16,
    .fb_base = 0x33c00000,


};

void lcd_4_3_add(void)
{
	register_lcd(&lcd_4_3_params);
}

