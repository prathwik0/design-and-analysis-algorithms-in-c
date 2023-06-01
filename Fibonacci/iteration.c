/* Simple C program to print the first n terms of fibonacci series */

#include <stdio.h>

void fibonacci(int n)
{
    int a = 0;
    int b = 1;
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", a);
        int temp = a;
        a = b;
        b += temp;
    }
}

int main()
{
    fibonacci(10);
}