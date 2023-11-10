
#include "./i2c_controller.h"

#define AT24CXX_ADDR	0x50

int at24cxx_write(unsigned int addr, unsigned char *data, int len)
{
	i2c_msg msg;
	int i;
	int err;
	unsigned char buf[2];
	/* 构造i2c_msg */
	for(i=0;i<len;i++)
	{
		buf[0] = addr++;
		buf[1] = data[i];
	/* 构造i2c_msg */
		msg.addr = AT24CXX_ADDR;
		msg.flags = 0;
		msg.len = 2;
		msg.buff = buf;
		msg.err = 0;
		msg.cnt_transferred = -1;
		err = i2c_transfer(&msg,1);
		if(err)
			return err;
	}
	return 0;
	/* 调用i2c_transfer */
}


int at24cxx_read(unsigned int addr, unsigned char *data, int len)
{	
	int err;
	i2c_msg msg[2];
	/* 构造i2c_msg */
	msg[0].addr = AT24CXX_ADDR;
	msg[0].flags = 0;
	msg[0].len = 1;
	msg[0].buff = &addr;
	msg[0].err = 0;
	msg[0].cnt_transferred = -1;

	msg[1].addr = AT24CXX_ADDR;
	msg[1].flags = 1;
	msg[1].len = len;
	msg[1].buff = data;
	msg[1].err = 0;
	msg[1].cnt_transferred = -1;
	/* 调用i2c_transfer */
	err = i2c_transfer(&msg,1);
	if(err)
		return err;
}

