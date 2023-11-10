 
#include "i2c_controller.h"

#define I2C_CONTROLLER_NUM 10


static p_i2c_controller P_i2c_controllers[I2C_CONTROLLER_NUM];
static p_i2c_controller p_i2c_con_selected;


/* 有一个i2c_controller数组用来存放各种不同芯片的操作结构体 */
void register_i2c_controller(p_i2c_controller *p)
{
    int i;
    for (i=0;i<I2C_CONTROLLER_NUM;i++)
    {
        if (!P_i2c_controllers[i])
        {
            P_i2c_controllers[i] = p;
            return;
        }
    }
}

/* 根据名字来选择某款I2C控制器 */
int select_i2c_controller(char *name)
{
    int i;
    for(i=0;i<I2C_CONTROLLER_NUM;i++)
    {
        if (P_i2c_controllers[i] && !strcmp(P_i2c_controllers[i]->name, name))
        {
            p_i2c_con_selected = P_i2c_controllers[i];
            return 0;
        }
    }
    return -1;
}

/* 实现 i2c_transfer 接口函数 */

int i2c_transfer(i2c_msg msgs, int num)
{
    return p_i2c_con_selected->master_xfer(msgs, num);
}

