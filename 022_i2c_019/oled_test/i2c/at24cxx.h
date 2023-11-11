
#ifndef __AT24CXX_H__
#define __AT24CXX_H__


int at24cxx_write(unsigned int addr, unsigned char *data, int len);
int at24cxx_read(unsigned int addr, unsigned char *data, int len);
void oled_write_1bit_cmd(unsigned char data);
void oled_write_1bit_dat(unsigned char data);
// int at24cxx_cmd(unsigned int cmd);


#endif
