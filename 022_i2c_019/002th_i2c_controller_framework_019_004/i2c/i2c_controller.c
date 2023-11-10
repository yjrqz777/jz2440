 
#include "i2c_controller.h"

#define I2C_CONTROLLER_NUM 10


static p_i2c_controller P_i2c_controllers[I2C_CONTROLLER_NUM];
static p_i2c_controller p_i2c_con_selected;


/* ��һ��i2c_controller����������Ÿ��ֲ�ͬоƬ�Ĳ����ṹ�� */
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

/* ����������ѡ��ĳ��I2C������ */
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

/* ʵ�� i2c_transfer �ӿں��� */

int i2c_transfer(i2c_msg msgs, int num)
{
    return p_i2c_con_selected->master_xfer(msgs, num);
}

