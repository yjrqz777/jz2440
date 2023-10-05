#include <stdio.h>

void test0()
{
    char c;
    char *pc;

    printf("&c =%p\n", &c);
    printf("&pc=%p\n", &pc);

    c='A';
    pc=&c;

    printf("c=%c\n", c);
    printf("pc=%p\n", pc);

}

void main()
{
    printf("sixeof(char)=%d\n", sizeof(char));
    printf("sixeof(int)=%d\n", sizeof(int));
    printf("sixeof(char *)=%d\n", sizeof(char *));
    printf("sixeof(char **)=%d\n", sizeof(char **));

    printf("====================================\n");

    test0();

}