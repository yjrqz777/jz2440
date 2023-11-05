
#ifndef _LCD_H_
#define _LCD_H_

enum {
    NORMAL = 0,
    INVERT = 1,
};



typedef struct pins_polarity {
    int vclk;           // noraml: 下降岩
    int rgb;            // normal: 高电平有效   
    int hsync;          // normal: 高电平有效
    int vsync;          // normal: 高电平有效
    int de;
    int pwren;
}pins_polarity, *p_pins_polarity;

typedef struct time_sequence {
    //垂直方向
    int tvp;            // vysnc 脉冲宽度
    int tvb;            // vysnc 后的黑框，上
    int tvf;            // vysnc 前的黑框，下


    //水平方向
    int thp;            // hsync 脉冲宽度
    int thb;            // hsync 后的黑框，左
    int thf;            // hsync 前的黑框，右

    int vclk;           // MHz


}time_sequence, *p_time_sequence;



typedef struct lcd_params{
    char *name;
    //引脚
    pins_polarity pins_pol;
    //时序
    time_sequence time_seq;
    //分辨率 bpp
    int xres;
    int yres;
    int bpp;
    //framebuffer 地址
    unsigned int fb_base;

}lcd_params, *p_lcd_params;






#endif
