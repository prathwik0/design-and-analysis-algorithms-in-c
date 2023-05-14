#include <stdio.h>
#include <stdlib.h>

int euclidAlg(int a, int b)
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

int min(int a, int b)
{
    return a > b ? b : a;
}

int consecutiveInt(int a, int b)
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

int middleSchool(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int i = 2, gcd = 1;

    while (a >= i && b >= i)
    {
        if (a % i == 0)
        {
            if (b % i == 0)
            {
                gcd = gcd * i;
                b = b / i;
            }
            a = a / i;
        }
        else
            i++;
    }
    return gcd;
}

int main()
{
    int a, b, gcd;
    printf("Enter the first number:  ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    gcd = euclidAlg(a, b);
    printf("\n1-GCD using Euclid's algorithm:   %d", gcd);

    gcd = consecutiveInt(a, b);
    printf("\n2-GCD using consecutive integers: %d", gcd);

    gcd = middleSchool(a, b);
    printf("\n3-GCD using mid school method:    %d", gcd);

    return 0;
}