 
#include  "my_printf.h"


//==================================================================================================
typedef char *  va_list;
#define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )

#define va_start(ap,v)  ( ap = (va_list)&v + _INTSIZEOF(v) )
//#define va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
#define va_arg(ap,t)    ( *(t *)( ap=ap + _INTSIZEOF(t), ap- _INTSIZEOF(t)) )
#define va_end(ap)      ( ap = (va_list)0 )

//==================================================================================================
unsigned char hex_tab[]={'0','1','2','3','4','5','6','7',\
		                 '8','9','a','b','c','d','e','f'};

static int outc(int c) 
{
	__out_putchar(c);
	return 0;
}

static int outs (const char *s)
{
	while (*s != '\0')	
		__out_putchar(*s++);
	return 0;
}

static int out_num(long n, int base,char lead,int maxwidth) 
{
	unsigned long m=0;
	char buf[MAX_NUMBER_BYTES], *s = buf + sizeof(buf);
	int count=0,i=0;
			

	*--s = '\0';
	
	if (n < 0){
		m = -n;
	}
	else{
		m = n;
	}
	
	do{
		*--s = hex_tab[m%base];
		count++;
	}while ((m /= base) != 0);
	
	if( maxwidth && count < maxwidth){
		for (i=maxwidth - count; i; i--)	
			*--s = lead;
}

	if (n < 0)
		*--s = '-';
	
	return outs(s);
}
   

/*reference :   int vprintf(const char *format, va_list ap); */
static int my_vprintf(const char *fmt, va_list ap) 
{
	char lead=' ';
	int  maxwidth=0;
	
	 for(; *fmt != '\0'; fmt++)
	 {
			if (*fmt != '%') {
				outc(*fmt);
				continue;
			}
			
		//format : %08d, %8d,%d,%u,%x,%f,%c,%s 
		    fmt++;
		if(*fmt == '0'){
			lead = '0';
			fmt++;	
		}
		
		while(*fmt >= '0' && *fmt <= '9'){
			maxwidth *=10;
			maxwidth += (*fmt - '0');
			fmt++;
		}
		
			switch (*fmt) {
		case 'd': out_num(va_arg(ap, int),          10,lead,maxwidth); break;
		case 'o': out_num(va_arg(ap, unsigned int),  8,lead,maxwidth); break;				
		case 'u': out_num(va_arg(ap, unsigned int), 10,lead,maxwidth); break;
		case 'x': out_num(va_arg(ap, unsigned int), 16,lead,maxwidth); break;
			case 'c': outc(va_arg(ap, int   )); break;		
			case 's': outs(va_arg(ap, char *)); break;		  		
				
			default:  
				outc(*fmt);
				break;
			}
	}
	return 0;
}


//reference :  int printf(const char *format, ...); 
int printf(const char *fmt, ...) 
{
	va_list ap;

	va_start(ap, fmt);
	my_vprintf(fmt, ap);	
	va_end(ap);
	return 0;
}


int my_printf_test(void)
{
	printf("This is www.100ask.org   my_printf test\n\r") ;	
	printf("test char           =%c,%c\n\r", 'A','a') ;	
	printf("test decimal number =%d\n\r",    123456) ;
	printf("test decimal number =%d\n\r",    -123456) ;	
	printf("test hex     number =0x%x\n\r",  0x55aa55aa) ;	
	printf("test string         =%s\n\r",    "www.100ask.org") ;	
	printf("num=%08d\n\r",   12345);
	printf("num=%8d\n\r",    12345);
	printf("num=0x%08x\n\r", 0x12345);
	printf("num=0x%8x\n\r",  0x12345);
	printf("num=0x%02x\n\r", 0x1);
	printf("num=0x%2x\n\r",  0x1);

	printf("num=%05d\n\r", 0x1);
	printf("num=%5d\n\r",  0x1);

	return 0;
}





// typedef char *  va_list;


 #ifdef  __cplusplus
 #define _ADDRESSOF(v)   ( &reinterpret_cast<const char &>(v) )
 #else
 #define _ADDRESSOF(v)   ( &(v) )
 #endif


 #define _INTSIZEOF(n)   ( (sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1) )




 #define _crt_va_start(ap,v)  ( ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v) )
 #define _crt_va_arg(ap,t)    ( *(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)) )
 #define _crt_va_end(ap)      ( ap = (va_list)0 )


 #define Test_va_start _crt_va_start /* windows stdarg.h */
 #define Test_va_arg _crt_va_arg
 #define Test_va_end _crt_va_end



 #define ZEROPAD    1       /* pad with zero */
 #define SIGN   2       /* unsigned/signed long */
 #define PLUS   4       /* show plus */
 #define SPACE  8       /* space if plus */
 #define LEFT   16      /* left justified */
 #define SPECIAL    32      /* 0x */
 #define LARGE  64      /* use 'ABCDEF' instead of 'abcdef' */

 int _div(long* n,unsigned base)
 {
     int __res; 
         __res = ((unsigned long) *n) % (unsigned) base; 
         *n = ((unsigned long) *n) / (unsigned) base; 
         return __res;
 }

#define do_div(n,base) _div(&n,base)/*({ \
    int __res; \
    __res = ((unsigned long) n) % (unsigned) base; \
    n = ((unsigned long) n) / (unsigned) base; \
    __res; })*/




 static inline int isdigit(int ch)
 {
    return (ch >= '0') && (ch <= '9');
 }



 static int skip_atoi(const char **s)
 {
    int i = 0;

    while (isdigit(**s))
        i = i * 10 + *((*s)++) - '0';
    return i;
 }



 static char *Test_number(char *str, long num, int base, int size, int precision,
    int type)
 {
    char c, sign, tmp[66];
    const char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";
    int i;

    if (type & LARGE)
        digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (type & LEFT)
        type &= ~ZEROPAD;
    if (base < 2 || base > 36)
        return 0;
    c = (type & ZEROPAD) ? '0' : ' ';
    sign = 0;
    if (type & SIGN) {
        if (num < 0) {
            sign = '-';
            num = -num;
            size--;
        } else if (type & PLUS) {
            sign = '+';
            size--;
        } else if (type & SPACE) {
            sign = ' ';
            size--;
        }
    }
    if (type & SPECIAL) {
        if (base == 16)
            size -= 2;
        else if (base == 8)
            size--;
    }
    i = 0;
    if (num == 0)
    {
        tmp[i++] = '0';
    }
    else
    {
        while (num != 0)
        {
            tmp[i++] = digits[do_div(num, base)];
        }
    }

    if (i > precision)
        precision = i;
    size -= precision;
    if (!(type & (ZEROPAD + LEFT)))
        while (size-- > 0)
            *str++ = ' ';
    if (sign)
        *str++ = sign;
    if (type & SPECIAL) {
        if (base == 8)
            *str++ = '0';
        else if (base == 16) {
            *str++ = '0';
            *str++ = digits[33];
        }
    }
    if (!(type & LEFT))
        while (size-- > 0)
            *str++ = c;
    while (i < precision--)
        *str++ = '0';
    while (i-- > 0)
        *str++ = tmp[i];
    while (size-- > 0)
        *str++ = ' ';
    return str;
 }

int con_strlen(const char *s,int maxlen)
{
    int i = 0;      
    while (s[i++] != '\0' && (i < maxlen))
        ;
    return i;
}



 int Test_vsprintf(char *buf, const char *fmt, va_list args)
 {
    int len;
    unsigned long num;
    int i, base;
    char *str;
    const char *s;

    int flags;      /* flags to Test_number() */

    int field_width;    /* width of output field */
    int precision;      /* min. # of digits for integers; max
                   Test_number of chars for from string */
    int qualifier;      /* 'h', 'l', or 'L' for integer fields */

    for (str = buf; *fmt; ++fmt) {
        if (*fmt != '%') {
            *str++ = *fmt;
            continue;
        }

        /* process flags */
        flags = 0;
          repeat:
        ++fmt;      /* this also skips first '%' */
        switch (*fmt) {
        case '-':
            flags |= LEFT;
            goto repeat;
        case '+':
            flags |= PLUS;
            goto repeat;
        case ' ':
            flags |= SPACE;
            goto repeat;
        case '#':
            flags |= SPECIAL;
            goto repeat;
        case '0':
            flags |= ZEROPAD;
            goto repeat;
        }

        /* get field width */
        field_width = -1;
        if (isdigit(*fmt))
            field_width = skip_atoi(&fmt);
        else if (*fmt == '*') {
            ++fmt;
            /* it's the next argument */
            field_width = Test_va_arg(args, int);
            if (field_width < 0) {
                field_width = -field_width;
                flags |= LEFT;
            }
        }

        /* get the precision */
        precision = -1;
        if (*fmt == '.') {
            ++fmt;
            if (isdigit(*fmt))
                precision = skip_atoi(&fmt);
            else if (*fmt == '*') {
                ++fmt;
                /* it's the next argument */
                precision = Test_va_arg(args, int);
            }
            if (precision < 0)
                precision = 0;
        }

        /* get the conversion qualifier */
        qualifier = -1;
        if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L') {
            qualifier = *fmt;
            ++fmt;
        }

        /* default base */
        base = 10;

        switch (*fmt) {
        case 'c':
            if (!(flags & LEFT))
                while (--field_width > 0)
                    *str++ = ' ';
            *str++ = (unsigned char)Test_va_arg(args, int);
            while (--field_width > 0)
                *str++ = ' ';
            continue;

        case 's':
            s = Test_va_arg(args, char *);
            len = con_strlen(s, precision);

            if (!(flags & LEFT))
                while (len < field_width--)
                    *str++ = ' ';
            for (i = 0; i < len; ++i)
                *str++ = *s++;
            while (len < field_width--)
                *str++ = ' ';
            continue;

        case 'p':
            if (field_width == -1) {
                field_width = 2 * sizeof(void *);
                flags |= ZEROPAD;
            }
            str = Test_number(str,
                     (unsigned long)Test_va_arg(args, void *), 16,
                     field_width, precision, flags);
            continue;

        case 'n':
            if (qualifier == 'l') {
                long *ip = Test_va_arg(args, long *);
                *ip = (str - buf);
            } else {
                int *ip = Test_va_arg(args, int *);
                *ip = (str - buf);
            }
            continue;

        case '%':
            *str++ = '%';
            continue;

            /* integer Test_number formats - set up the flags and "break" */
        case 'o':
            base = 8;
            break;

        case 'X':
            flags |= LARGE;
        case 'x':
            base = 16;
            break;

        case 'd':
        case 'i':
            flags |= SIGN;
        case 'u':
            break;

        default:
            *str++ = '%';
            if (*fmt)
                *str++ = *fmt;
            else
                --fmt;
            continue;
        }
        if (qualifier == 'l')
            num = Test_va_arg(args, unsigned long);
        else if (qualifier == 'h') {
            num = (unsigned short)Test_va_arg(args, int);
            if (flags & SIGN)
                num = (short)num;
        } else if (flags & SIGN)
            num = Test_va_arg(args, int);
        else
            num = Test_va_arg(args, unsigned int);
        str = Test_number(str, num, base, field_width, precision, flags);
    }
    *str = '\0';
    return str - buf;
 }


 int Test_sprintf(char *buf, const char *fmt, ...)
{
    //记录fmt对应的地址
    va_list args;
    int val;
    //得到首个%对应的字符地址
    Test_va_start(args, fmt);
    val = Test_vsprintf(buf, fmt, args);
    Test_va_end(args);
    return val;
}


