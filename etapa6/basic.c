#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int x = 1;
int y = 2;
int t = 17; 
int soma(int a, int b)
{
    t = a + b;
    printf("t = %d\n", t);
    return t;
}
int main()
{
    printf("x + y = %d\n", x + y);
    printf("soma de x com y = %d\n", soma(x,y));
    return 0;
}