#include "bubbleSort.h"
#include "insertionSort.h"
#include "selectionSort.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create an array of sorting functions
    void (*sortingFunctions[])(int *, int) = {bubbleSort,
                                              selectionSort,
                                              insertionSort};

    // Provide the names for the given sorting functions
    const char *sortingFunctionNames[] = {"Bubble Sort   ",
                                          "Selection Sort",
                                          "Insertion Sort"};

    // Find the number of sorting functions present
    int numFunctions = sizeof(sortingFunctions) / sizeof(sortingFunctions[0]);

    // Test the sorting functions
    test(sortingFunctions, sortingFunctionNames, numFunctions, 10000, 0, 1000000, 400);

    return 0;
}
