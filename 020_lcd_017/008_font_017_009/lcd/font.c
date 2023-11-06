

extern const unsigned char fontdata_8x16[];


static unsigned int fb_base;
static int xres,yres,bpp;

void font_init(void)
{
    get_lcd_params(&fb_base,&xres,&yres,&bpp);
}


void fb_print_char(int x,int y, char c, int color)
{
    unsigned char *dots = &fontdata_8x16[c * 16];

    int i,j;
    unsigned char data;

    for(j=y;j<y+16;j++)
    {
        data=*dots++;
        for(i=x;i<x+8;i++)
        {
            if(data & (1<<(7-(i-x))))
                fb_put_pixel(i,j,color);
        }
    }




}


void fb_print_string(int x,int y, char *string, int color)
{
    int i=0,j;
    while(string[i])
    {
        if(string[i]=='\n')
            y=y+16;
        else if(string[i]=='\r')
            x=0;
        else 
        {
            fb_print_char(x,y,string[i],color);
            x=x+8;
            if(x>=xres)
            {
                x=0;
                y=y+16;
            }
            
        }
        i++;
    }

}
