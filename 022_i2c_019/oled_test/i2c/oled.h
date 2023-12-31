#ifndef __OLED_H
#define __OLED_H


#define  u8 unsigned char 
#define  u16 unsigned int
#define  u32 unsigned int
	
#define OLED_CMD  0	//写命令
#define OLED_DATA 1	//写数据


//-----------------OLED端口定义----------------



//OLED控制用函数
void delay_ms(unsigned int ms);
void OLED_ColorTurn(u8 i);
void OLED_DisplayTurn(u8 i);
void OLED_WR_Byte(u8 dat,u8 cmd);
void OLED_Set_Pos(u8 x, u8 y);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Clear(u8 color);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size1,u8 mode);
u32 oled_pow(u8 m,u8 n);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 sizey,u8 mode);
void OLED_ShowString(u8 x,u8 y,u8 *chr,u8 sizey,u8 mode);
void OLED_ShowChinese(u8 x,u8 y,u8 no,u8 sizey,u8 mode);
void OLED_DrawBMP(u8 x,u8 y,u8 sizex, u8 sizey,u8 BMP[]);
void OLED_Init(void);
void OLED_Refresh(void);
void OLED_ScrollDisplay(u8 num,u8 space,u8 mode);
void OLED_ShowPicture(u8 x,u8 y,u8 sizex,u8 sizey,u8 BMP[],u8 mode);
#endif  
	 



