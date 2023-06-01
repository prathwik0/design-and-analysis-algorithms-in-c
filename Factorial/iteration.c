/* Simple factorial program in C using iteration */

#include <stdio.h>

int fact(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main()
{
    int n = 10;
    printf("Factorial of %d is %d\n", n, fact(n));
    return 0;
}