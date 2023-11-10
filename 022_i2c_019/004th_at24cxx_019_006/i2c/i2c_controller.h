
#ifndef _I2C_CONTROLLER_H_

#define _I2C_CONTROLLER_H_



typedef struct i2c_msg{
    unsigned int addr;
    int flags;
    int len;
    int cnt_transferred;
    int err;
    unsigned char *buff;
}i2c_msg,*p_i2c_msg;

typedef struct i2c_controller{
    int (*init)(void);
    int (*master_xfer)(p_i2c_msg msgs,int num);
    char *name;
}i2c_controller,*p_i2c_controller;

void i2c_init();

int i2c_transfer(p_i2c_msg msgs, int num);

#endif
