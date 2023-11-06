
#ifndef _FONT_H_
#define _FONT_H_

void font_init(void);
void fb_print_char(int x,int y, char c, int color);
void fb_print_string(int x,int y, char *string, int color);


#endif