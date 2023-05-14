// C program to find GCD using middle school method
#include <stdio.h>
#include <stdlib.h>

// A function to return all prime factors of a given number n
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

// Function to return gcd of a and b
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
    while (p = coprimes[i])
    {
        i++;
        gcd *= p;
    }

    return gcd;
}

// Driver program to test above function
int main()
{
    int a = 10, b = 15;
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    a = 35, b = 14;
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    // gcd(9888,6060) = 12
    a = 9888, b = 6060;
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    // GCD(1160718174, 316258250) = 1078
    a = 1160718174, b = 316258250;
    printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    return 0;
}