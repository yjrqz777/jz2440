

// #include "oled.h"
// #include "./oledfont.h"
// #include "./bmp.h"
// #include "./i2c_controller.h"

// #define AT24CXX_ADDR	0x3c
// unsigned char OLED_GRAM[144][8];

// int ssd1315_i2c_send(unsigned char cmd,unsigned char mode)
// {	
//     i2c_msg msg2;
// 	int err;
//     int i;
//     unsigned char buf[2];
//     if(mode)
//         buf[0] = 0x40;
//     else   
//         buf[0] = 0x00;
//     buf[1] = cmd;
//     // printf("buf[0]=%d,buf[1]=%d,cmd=%d\n\r",buf[0],buf[1],cmd);
//     msg2.addr = AT24CXX_ADDR;
//     msg2.flags = 0;
//     msg2.len = 2;
//     msg2.buf = buf;
//     msg2.err = 0;
//     msg2.cnt_transferred = -1;
//     err = i2c_transfer(&msg2,1);
//     if(err)
//         return err;
//     return 0;
// 	/* 调用i2c_transfer */

// }

// void oled_test()
// {
//     u8 t=' ';
//     int i=5;
// 	OLED_Init();//初始化OLED
// 	OLED_ColorTurn(0);//0正常显示，1 反色显示
//   OLED_DisplayTurn(0);//0正常显示 1 屏幕翻转显示
// 	while(i--) 
// 	{		
// 		OLED_DrawBMP(0,0,128,64,BMP1);
// 		delay_ms(500);
// 		OLED_Clear(0);
// 		OLED_ShowChinese(0,0,0,16);//中
// 		OLED_ShowChinese(18,0,1,16);//景
// 		OLED_ShowChinese(36,0,2,16);//园
// 		OLED_ShowChinese(54,0,3,16);//电
// 		OLED_ShowChinese(72,0,4,16);//子
// 		OLED_ShowChinese(90,0,5,16);//科
// 		OLED_ShowChinese(108,0,6,16);//技
// 		OLED_ShowString(8,2,"ZHONGJINGYUAN",16);
// 		OLED_ShowString(20,4,"2014/05/01",16);
// 		OLED_ShowString(0,6,"ASCII:",16);  
// 		OLED_ShowString(63,6,"CODE:",16);
// 		OLED_ShowChar(48,6,t,16);
// 		t++;
// 		if(t>'~')t=' ';
// 		OLED_ShowNum(103,6,t,3,16);
// 		delay_ms(500);
// 		OLED_Clear(0);
// 	}
// }



// /********************************************  
// *	init_oled
// *	初始化OLED 屏幕
// ********************************************/

// void OLED_Init(void)
// {
// 	ssd1315_i2c_send(0xAE,OLED_CMD);//--turn off oled panel
// 	ssd1315_i2c_send(0x00,OLED_CMD);//---set low column address
// 	ssd1315_i2c_send(0x10,OLED_CMD);//---set high column address
// 	ssd1315_i2c_send(0x40,OLED_CMD);//--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
// 	ssd1315_i2c_send(0x81,OLED_CMD);//--set contrast control register
// 	ssd1315_i2c_send(0xCF,OLED_CMD);// Set SEG Output Current Brightness
// 	ssd1315_i2c_send(0xA1,OLED_CMD);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
// 	ssd1315_i2c_send(0xC8,OLED_CMD);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
// 	ssd1315_i2c_send(0xA6,OLED_CMD);//--set normal display
// 	ssd1315_i2c_send(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
// 	ssd1315_i2c_send(0x3f,OLED_CMD);//--1/64 duty
// 	ssd1315_i2c_send(0xD3,OLED_CMD);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
// 	ssd1315_i2c_send(0x00,OLED_CMD);//-not offset
// 	ssd1315_i2c_send(0xd5,OLED_CMD);//--set display clock divide ratio/oscillator frequency
// 	ssd1315_i2c_send(0x80,OLED_CMD);//--set divide ratio, Set Clock as 100 Frames/Sec
// 	ssd1315_i2c_send(0xD9,OLED_CMD);//--set pre-charge period
// 	ssd1315_i2c_send(0xF1,OLED_CMD);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
// 	ssd1315_i2c_send(0xDA,OLED_CMD);//--set com pins hardware configuration
// 	ssd1315_i2c_send(0x12,OLED_CMD);
// 	ssd1315_i2c_send(0xDB,OLED_CMD);//--set vcomh
// 	ssd1315_i2c_send(0x30,OLED_CMD);//Set VCOM Deselect Level
// 	ssd1315_i2c_send(0x20,OLED_CMD);//-Set Page Addressing Mode (0x00/0x01/0x02)
// 	ssd1315_i2c_send(0x02,OLED_CMD);//
// 	ssd1315_i2c_send(0x8D,OLED_CMD);//--set Charge Pump enable/disable
// 	ssd1315_i2c_send(0x14,OLED_CMD);//--set(0x10) disable
// 	OLED_Clear(0);
// 	ssd1315_i2c_send(0xAF,OLED_CMD); /*display ON*/ 

//     delay(10000);
//     OLED_Clear(255);
//     delay(10000);
//     OLED_Clear(0);
// }


// void delay_ms(unsigned int ms)
// {                         
// 	unsigned int a;
// 	while(ms)
// 	{
// 		a=1800;
// 		while(a--);
// 		ms--;
// 	}
// 	return;
// }

// //反显函数
// void OLED_ColorTurn(u8 i)
// {
// 	if(i==0)
// 		{
// 			ssd1315_i2c_send(0xA6,OLED_CMD);//正常显示
// 		}
// 	if(i==1)
// 		{
// 			ssd1315_i2c_send(0xA7,OLED_CMD);//反色显示
// 		}
// }

// //屏幕旋转180度
// void OLED_DisplayTurn(u8 i)
// {
// 	if(i==0)
// 		{
// 			ssd1315_i2c_send(0xC8,OLED_CMD);//正常显示
// 			ssd1315_i2c_send(0xA1,OLED_CMD);
// 		}
// 	if(i==1)
// 		{
// 			ssd1315_i2c_send(0xC0,OLED_CMD);//反转显示
// 			ssd1315_i2c_send(0xA0,OLED_CMD);
// 		}
// }










// //坐标设置

// void OLED_Set_Pos(u8 x, u8 y) 
// { 
// 	ssd1315_i2c_send(0xb0+y,OLED_CMD);
// 	ssd1315_i2c_send(((x&0xf0)>>4)|0x10,OLED_CMD);
// 	ssd1315_i2c_send((x&0x0f),OLED_CMD);
// }   	  
// //开启OLED显示    
// void OLED_Display_On(void)
// {
// 	ssd1315_i2c_send(0X8D,OLED_CMD);  //SET DCDC命令
// 	ssd1315_i2c_send(0X14,OLED_CMD);  //DCDC ON
// 	ssd1315_i2c_send(0XAF,OLED_CMD);  //DISPLAY ON
// }
// //关闭OLED显示     
// void OLED_Display_Off(void)
// {
// 	ssd1315_i2c_send(0X8D,OLED_CMD);  //SET DCDC命令
// 	ssd1315_i2c_send(0X10,OLED_CMD);  //DCDC OFF
// 	ssd1315_i2c_send(0XAE,OLED_CMD);  //DISPLAY OFF
// }		   			 
// //清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!	  
// void OLED_Clear(unsigned char color)  
// {  
// 	u8 i,n;		    
// 	for(i=0;i<8;i++)  
// 	{  
// 		ssd1315_i2c_send (0xb0+i,OLED_CMD);    //设置页地址（0~7）
// 		ssd1315_i2c_send (0x00,OLED_CMD);      //设置显示位置—列低地址
// 		ssd1315_i2c_send (0x10,OLED_CMD);      //设置显示位置—列高地址   
// 		for(n=0;n<128;n++)ssd1315_i2c_send(color,OLED_DATA); 
// 	} //更新显示
// }

// //在指定位置显示一个字符,包括部分字符
// //x:0~127
// //y:0~63				 
// //sizey:选择字体 6x8  8x16
// void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 sizey)
// {      	
// 	u8 c=0,sizex=sizey/2;
// 	u16 i=0,size1;
// 	if(sizey==8)size1=6;
// 	else size1=(sizey/8+((sizey%8)?1:0))*(sizey/2);
// 	c=chr-' ';//得到偏移后的值
// 	OLED_Set_Pos(x,y);
// 	for(i=0;i<size1;i++)
// 	{
// 		if(i%sizex==0&&sizey!=8) OLED_Set_Pos(x,y++);
// 		if(sizey==8) ssd1315_i2c_send(asc2_0806[c][i],OLED_DATA);//6X8字号
// 		else if(sizey==16) ssd1315_i2c_send(asc2_1608[c][i],OLED_DATA);//8x16字号
// //		else if(sizey==xx) ssd1315_i2c_send(asc2_xxxx[c][i],OLED_DATA);//用户添加字号
// 		else return;
// 	}
// }
// //m^n函数
// u32 oled_pow(u8 m,u8 n)
// {
// 	u32 result=1;	 
// 	while(n--)result*=m;    
// 	return result;
// }				  
// //显示数字
// //x,y :起点坐标
// //num:要显示的数字
// //len :数字的位数
// //sizey:字体大小		  
// void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 sizey)
// {         	
// 	u8 t,temp,m=0;
// 	u8 enshow=0;
// 	if(sizey==8)m=2;
// 	for(t=0;t<len;t++)
// 	{
// 		temp=(num/oled_pow(10,len-t-1))%10;
// 		if(enshow==0&&t<(len-1))
// 		{
// 			if(temp==0)
// 			{
// 				OLED_ShowChar(x+(sizey/2+m)*t,y,' ',sizey);
// 				continue;
// 			}else enshow=1;
// 		}
// 	 	OLED_ShowChar(x+(sizey/2+m)*t,y,temp+'0',sizey);
// 	}
// }
// //显示一个字符号串
// void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 sizey)
// {
// 	u8 j=0;
// 	while (chr[j]!='\0')
// 	{		
// 		OLED_ShowChar(x,y,chr[j++],sizey);
// 		if(sizey==8)x+=6;
// 		else x+=sizey/2;
// 	}
// }
// //显示汉字
// void OLED_ShowChinese(u8 x,u8 y,u8 no,u8 sizey)
// {
// 	u16 i,size1=(sizey/8+((sizey%8)?1:0))*sizey;
// 	for(i=0;i<size1;i++)
// 	{
// 		if(i%sizey==0) OLED_Set_Pos(x,y++);
// 		if(sizey==16) ssd1315_i2c_send(Hzk[no][i],OLED_DATA);//16x16字号
// //		else if(sizey==xx) ssd1315_i2c_send(xxx[c][i],OLED_DATA);//用户添加字号
// 		else return;
// 	}				
// }


// //显示图片
// //x,y显示坐标
// //sizex,sizey,图片长宽
// //BMP：要显示的图片
// void OLED_DrawBMP(u8 x,u8 y,u8 sizex, u8 sizey,u8 BMP[])
// { 	
//   u16 j=0;
// 	u8 i,m;
// 	sizey=sizey/8+((sizey%8)?1:0);
// 	for(i=0;i<sizey;i++)
// 	{
// 		OLED_Set_Pos(x,i+y);
//     for(m=0;m<sizex;m++)
// 		{      
// 			ssd1315_i2c_send(BMP[j++],OLED_DATA);	    	
// 		}
// 	}
// } 


