#include "test.h"
#include <stdio.h>

int gcd(int a, int b)
{
    int rem;
    while (b != 0)
    {
        rem = a % b;
        a = b;
        b = rem;
    }
    return (a);
}

int main()
{
    test();
    return 0;
}