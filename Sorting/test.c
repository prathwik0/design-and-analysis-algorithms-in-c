#include "test.h"
#include <stdio.h>
#include <stdlib.h> /*for memory allocation*/
#include <time.h>   /*for random number generation & clock*/

// make sure to free the array receieved by this function if used
int *generateUniqueRandIntegers(int min, int max, int count)
{
    if (count > (max - min + 1))
    {
        printf("Error: Cannot generate more unique random numbers than the range allows.\n");
        return NULL;
    }

    if (min > max)
    {
        printf("Error: Invalid range.\n");
        return NULL;
    }

    int rangeSize = max - min + 1;
    int *numbers = malloc(rangeSize * sizeof(int));
    if (numbers == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    // Initialize the array
    for (int i = 0; i < rangeSize; i++)
    {
        numbers[i] = min + i;
    }

    // Shuffle the array using Fisher-Yates algorithm
    srand(time(NULL));
    for (int i = rangeSize - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }

    // Create a new array to store the selected unique random numbers
    int *selectedNumbers = malloc(count * sizeof(int));
    if (selectedNumbers == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        free(numbers);
        return NULL;
    }

    // Copy the first 'count' elements from the shuffled array to the selectedNumbers array
    for (int i = 0; i < count; i++)
    {
        selectedNumbers[i] = numbers[i];
    }

    free(numbers);
    return selectedNumbers;
}

int isSorted(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return 0;
        }
    }
    return 1;
}

int *allocateArray(int size)
{
    int *newArray = malloc(2 * size * sizeof(int)); /*Allocate memory for destination array*/

    if (newArray == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return NULL; /* Return NULL if memory allocation fails */
    }

    return newArray;
}

void copyArray(const int *sourceArray, int *destinationArray, int size)
{
    // Copy the element of first array into the second array
    for (int i = 0; i < size; i++)
    {
        destinationArray[i] = sourceArray[i];
    }
}

void test(void (*sort[])(int *, int), const char *sortFuncNames[], int numFunc, int nIter, int min, int max, int count)
{
    // average time taken to sort
    double avg[numFunc];

    for (int i = 0; i < nIter; i++)
    {
        int *testArray = generateUniqueRandIntegers(min, max, count);
        int *testArrayCopy = allocateArray(count);
        if (testArrayCopy == NULL)
        {
            printf("Aborting the program\n");
            free(testArray);
            return;
        }
        copyArray(testArray, testArrayCopy, count);

        for (int j = 0; j < numFunc; j++)
        {
            clock_t start_time = clock();
            sort[j](testArrayCopy, count);
            clock_t end_time = clock();

            double sorting_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            avg[j] += sorting_time / nIter;

            // Verify the sorted array & print the results
            if (isSorted(testArrayCopy, count))
            {
                printf("Sorting Time of %s : %lf\n", sortFuncNames[j], sorting_time);
            }
            else
            {
                printf("ERROR: Array was not sorted correctly.");
            }

            // Recopy the testArray to testArrayCopy
            copyArray(testArray, testArrayCopy, count);
        }

        // Free the dynamically allocated memory
        free(testArray);
        free(testArrayCopy);
    }
}
