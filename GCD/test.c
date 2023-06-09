#include "test.h"
#include <stdio.h>

void test()
{
    // Test cases
    int testCases[][7] = {
        {10, 25, 5},
        {14, 28, 14},
        {45, 18, 9},
        {27, 81, 27},
        {17, 29, 1},
        {9888, 6060, 12},
        {1160718174, 316258250, 1078}};

    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int i = 0; i < numTestCases; i++)
    {
        int a = testCases[i][0];
        int b = testCases[i][1];
        int expectedGCD = testCases[i][2];

        int result = gcd(a, b);

        if (result == expectedGCD)
            printf("Test case %d passed: GCD %d, %d = %d\n", i + 1, a, b, result);
        else
            printf("Test case %d failed: Expected %d, got %d\n", i + 1, expectedGCD, result);
    }
}