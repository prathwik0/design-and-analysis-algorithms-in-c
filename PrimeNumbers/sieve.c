// C program to print all primes smaller than or equal to n
// using Sieve of Eratosthenes
#include <stdio.h>
#include <stdbool.h>
#include <string.h> //for memset

void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            printf("%d ", p);

    printf("\n");
}

// Driver Code
int main()
{
    int n = 1000;
    printf("Prime numbers <= %d are:\n", n);
    SieveOfEratosthenes(n);
    return 0;
}
