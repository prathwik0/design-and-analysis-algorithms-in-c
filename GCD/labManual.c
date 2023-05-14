#include <stdio.h>
#include <stdlib.h>

int euclidAlg(int m, int n)
{
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }
    return (m);
}

int min(int a, int b)
{
    if (a > b)
        return b;
    else
        return a;
}

int consecutiveInt(int m, int n)
{
    int t;
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    t = min(m, n);
    while (t != 0)
    {
        if (m % t == 0)
        {
            if (n % t == 0)
            {
                return (t);
            }
        }
        t--;
    }
    return (-1);
}

int middleSchool(int m, int n)
{
    int a = 2, g = 1;
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    while ((m >= a && m != 0) && (n >= a && n != 0))
    {
        if (m % a == 0)
        {
            if (n % a == 0)
            {
                g = g * a;
                n = n / a;
            }
            m = m / a;
        }
        else
            a++;
    }
    return g;
}

int main()
{
    int m, n, ch, gcd;
    printf("Enter the first number:  ");
    scanf("%d", &m);
    printf("Enter the second number: ");
    scanf("%d", &n);

    gcd = euclidAlg(m, n);
    printf("\n1-GCD using Euclid's algorithm:   %d", gcd);

    gcd = consecutiveInt(m, n);
    printf("\n2-GCD using consecutive integers: %d", gcd);

    gcd = middleSchool(m, n);
    printf("\n3-GCD using mid school method:    %d", gcd);

    return 0;
}