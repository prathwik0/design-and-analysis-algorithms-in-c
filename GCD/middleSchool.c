#include "test.h"
#include <stdlib.h>

int *primeFactors(int n)
{
    int *primes = (int *)calloc(100, sizeof(int));
    int pos = 0;

    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        primes[pos] = 2;
        pos++;
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    // one element (Note i = i + 2)
    for (int i = 3; i * i <= n; i = i + 2)
    {
        // While i divides n, add i to the list of prime numbers and divide by n
        while (n % i == 0)
        {
            primes[pos] = i;
            pos++;
            n = n / i;
        }
    }

    // This condition is to handle the case when n
    // is a prime number greater than 2
    if (n > 2)
        primes[pos] = n;
    pos++;

    return primes;
}

int gcd(int a, int b)
{
    int *arr1 = primeFactors(a);
    int *arr2 = primeFactors(b);

    int *coprimes = (int *)calloc(100, sizeof(int));

    int p, q;
    int i = 0, j = 0, k = 0;

    while ((p = arr1[i]) && (q = arr2[j]))
    {
        if (p == q)
        {
            coprimes[k] = p;
            i++;
            j++;
            k++;
        }
        else if (p < q)
            i++;
        else
            j++;
    }

    int gcd = 1;
    i = 0;
    while ((p = coprimes[i]))
    {
        i++;
        gcd *= p;
    }

    return gcd;
}

int main()
{
    test();
    return 0;
}