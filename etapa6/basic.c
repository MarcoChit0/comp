#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int soma(
    int a0, int b0,
    int a1, int b1,
    int a2, int b2,
    int a3, int b3,
    int a4, int b4,
    int a5, int b5,
    int a6, int b6)
{
    return a0 + b0 + a1 + b1 + a2 + b2 + a3 + b3 + a4 + b4 + a5 + b5 + a6 + b6;
}
int m = 2;
int n = 3;
int main()
{
    m = soma(m, n,m, n,m, n,m, n,m, n,m, n,m, n);
    return 0;
}