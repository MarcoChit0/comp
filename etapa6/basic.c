#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a=1;
int b=2;
int soma(int n, int m)
{
    return m + n;
}
int main()
{
    printf("soma de a com b = %d\n", soma(a,b));
    return 0;
}