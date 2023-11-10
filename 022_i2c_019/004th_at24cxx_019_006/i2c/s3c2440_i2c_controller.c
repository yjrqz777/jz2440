
#include "i2c_controller.h"
#include "../s3c2440_soc.h"

static p_i2c_msg p_cur_msg;

void i2c_intterrput_func(int irq)
{

    unsigned int iicstat = IICSTAT;
    int index;
    p_cur_msg->cnt_transferred++;
    if(p_cur_msg->flags==0)//发送
    {
        if(p_cur_msg->cnt_transferred==0)
        {
            if(iicstat & (1<<0))
            {
                IICSTAT = 0xd0;
                IICCON &= ~(1<<4);
                p_cur_msg->err=-1;
                delay(1000);
                return;
            }

        }

        if(p_cur_msg->cnt_transferred<p_cur_msg->len)
        {
            IICDS = p_cur_msg->buff[p_cur_msg->cnt_transferred];
            IICCON &= ~(1<<4);
        }
        else
        {
            IICSTAT = 0x90;
            IICCON &= ~(1<<4);
            p_cur_msg->err=-1;
            delay(1000);
        }


    }
    else//接收
    {
        if(p_cur_msg->cnt_transferred==0)
        {
            if(iicstat & (1<<0))
            {
                IICSTAT = 0xd0;
                IICCON &= ~(1<<4);
                p_cur_msg->err=-1;
                delay(1000);
                return;
            }
            else{
                IICCON &= ~(1<<4);
                return;
            }
        }
        if(p_cur_msg->cnt_transferred<p_cur_msg->len)
        {
            index=p_cur_msg->cnt_transferred-1;
            p_cur_msg->buff[index]=IICDS;
            IICCON &= ~(1<<4);
        }
        else{
            IICSTAT=0x90;
            IICCON &= ~(1<<4);
            delay(1000);
        }

    }
}

void s3c2440_i2c_init(void)
{
    IICCON =  (1<<7)|(0<<6)|(1<<5)|(30<<0);
    register_irq(0, i2c_intterrput_func);

}

int do_maseter_tx(p_i2c_msg msgs)
{   
    p_cur_msg = msgs;
    msgs->cnt_transferred=-1;
    msgs->err=0;
    IICDS = msgs->addr<<1;
    IICSTAT = 0xf0;

    while(!msgs->err && msgs->cnt_transferred!=msgs->len);
    if(msgs->err)
        return -1;
    else 
        return 0;
}
int do_master_rx(p_i2c_msg msgs)
{

    p_cur_msg = msgs;
    msgs->cnt_transferred=-1;
    IICDS = (msgs->addr<<1)|(1<<0);
    IICSTAT = 0xb0;

    while(!msgs->err && msgs->cnt_transferred!=msgs->len);
    if(msgs->err)
        return -1;
    else 
        return 0;
}

int s3c2440_i2c_master_xfer(p_i2c_msg msgs,int num)
{
    int i;
    int err;
    for(i=0;i<num ;i++)
    {
        if(msgs->flags == 0)
            err = do_maseter_tx(msgs);
        else
            err = do_master_rx(msgs);
        if(err)
            return err;
    }
    return 0;
}

static p_i2c_controller s3c2440_i2c_con = 
{
    .init = s3c2440_i2c_init,
    .master_xfer = s3c2440_i2c_master_xfer,
    .name = "s3c2440_i2c_controller",
};


void s3c2440_i2c_con_add(void)
{
    register_i2c_controller(&s3c2440_i2c_con);
}

