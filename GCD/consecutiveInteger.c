#include "test.h"

int min(int a, int b)
{
    return a > b ? b : a;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int gcd = min(a, b);
    while (gcd != 0)
    {
        if (a % gcd == 0)
        {
            if (b % gcd == 0)
            {
                return (gcd);
            }
        }
        gcd--;
    }
    return (-1);
}

int main()
{
    test();
    return 0;
}