#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void test()
{
    // Generate a sorted array of numbers from 1 to n
    int n = 1000000;
    int *numbers = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        numbers[i] = i + 1;
    }

    // Target value to search for
    int n2 = 1000;
    int *targets = (int *)malloc(n2 * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n2; i++)
    {
        targets[i] = (rand() % (2 * n - 0 + 1)) + 0; // % (upper - lower + 1) + lower
    }

    // Test linear search
    int pos;
    clock_t start_time = clock();
    for (int i = 0; i < n2; i++)
    {
        pos = search(numbers, n, targets[i]);
        printf("Iter %d - Found at pos: %d\n", i, pos);
    }
    clock_t end_time = clock();
    double search_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Print the results
    printf("Search Time: %lf\n", search_time);

    // Free the dynamically allocated memory
    free(numbers);
    free(targets);
}
