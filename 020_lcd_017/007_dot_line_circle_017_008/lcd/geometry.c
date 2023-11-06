
#include "framebuffer.h"
#include "geometry.h"

void DrawLine(int  x1, int  y1, int  x2, int y2,int color)
{
  int t;
  int xerr = 0, yerr = 0, delta_x, delta_y, distance;
  int incx, incy, uRow, uCol;
  delta_x = x2 - x1; /* 计算坐标增量 */
  delta_y = y2 - y1;
  uRow = x1;
  uCol = y1;
  if (delta_x > 0) /* 设置单步方向 */
    incx = 1;
  else if (delta_x == 0) /* 垂直线 */
    incx = 0;
  else
  {
    incx = -1;
    delta_x = -delta_x;
  }

  if (delta_y > 0)
    incy = 1;
  else if (delta_y == 0) /* 水平线 */
    incy = 0;
  else
  {
    incy = -1;
    delta_y = -delta_y;
  }

  if (delta_x > delta_y) /*选取基本增量坐标轴  */
    distance = delta_x;
  else
    distance = delta_y;

  for (t = 0; t <= distance; t++) /* 画线输出 */
  {

    fb_put_pixel(uRow, uCol, color);
    xerr += delta_x;
    yerr += delta_y;
    if (xerr + distance / 2 > distance)
    {
      xerr -= distance;
      uRow += incx;
    }
    if (yerr + distance / 2 > distance)
    {
      yerr -= distance;
      uCol += incy;
    }
  }
}


void draw_circle(int a,int b,int r,int color)
{
	int i,j;
	i=j=0;
	while((i+j!=r)&&(i+j!=r+1))
	{	
		fb_put_pixel(a+i,b+r-j,color);
		fb_put_pixel(a+i,b-r+j,color);
		fb_put_pixel(a-i,b+r-j,color);
		fb_put_pixel(a-i,b-r+j,color);
		
		fb_put_pixel(a+r-j,b+i,color);
		fb_put_pixel(a-r+j,b+i,color);
		fb_put_pixel(a+r-j,b-i,color);
		fb_put_pixel(a-r+j,b-i,color);
		if(4*(i+1)*(i+1)+(2*r-2*j+1)*(2*r-2*j+1)>4*r*r)
		{
			j++;
		}		
		i++;	
	}
}

