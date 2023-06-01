/* Simple factorial program in C using recursion */

#include <stdio.h>

int fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int n = 10;
    printf("Factorial of %d is %d\n", n, fact(n));
    return 0;
}