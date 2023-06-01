/* Simple C program to print the first n terms of fibonacci series */
/* ps. don't use recursion for fibonacci!!! */

#include <stdio.h>

int fib(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n = 10;
    printf("The first %d terms of fibonacci series are:\n", n);

    for (int i = 1; i <= n; i++)
        printf("%d\n", fib(i));

    return 0;
}