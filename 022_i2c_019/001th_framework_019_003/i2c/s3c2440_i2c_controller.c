
#include "i2c_controller.h"
#include "../s3c2440_soc.h"


void i2c_intterrput_func(int irq)
{


}

void s3c2440_i2c_init(void)
{
    IICCON =  (0<<6)|(1<<5)|(30<<0);
    register_irq(0, i2c_intterrput_func);

}

void do_maseter_tx(p_i2c_msg msgs)
{
    msgs->cnt_transferred=0;
    IICDS = msgs->addr<<1;
    IICSTAT = 0xf0;

    while(msgs->cnt_transferred!=msgs->len)
    {

    }
}
void do_master_rx(p_i2c_msg msgs)
{
    msgs->cnt_transferred=0;
    IICDS = (msgs->addr<<1)|(1<<0);
    IICSTAT = 0xb0;

    while(msgs->cnt_transferred!=msgs->len)
    {
        
    }
}

int s3c2440_i2c_master_xfer(p_i2c_msg msgs,int num)
{
    int i;
    for(i=0;i<num ;i++)
    {
        if(msgs->flags == 0)
            do_maseter_tx(msgs);
        else
            do_master_rx(msgs);
    }
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

