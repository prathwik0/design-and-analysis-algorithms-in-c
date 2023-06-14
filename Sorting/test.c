#include <stdio.h>
#include <stdlib.h> /*for memory allocation*/
#include <time.h>   /*for random number generation & clock*/

static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int *allocateArray(int size)
{
    int *newArray = malloc(size * sizeof(int)); /*Allocate memory for destination array*/

    if (newArray == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return NULL; /* Return NULL if memory allocation fails */
    }

    return newArray;
}

static void generateUniqueRandIntegers(int *array, int min, int max, int count)
{
    int N = max - min - 1;

    int *largerArray = allocateArray(N);
    if (largerArray == NULL)
    {
        return;
    }

    for (int i = 0; i < N - 1; i++)
    {
        largerArray[i] = i + 1;
    }

    // randomize the array
    srand(time(0));
    for (int i = N - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(&largerArray[i], &largerArray[j]);
    }

    for (int i = 0; i < count; i++)
    {
        array[i] = largerArray[i] + min;
        // printf("%d\n", array[i]);
    }

    free(largerArray);
}

static int isSorted(int arr[], int size)
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

static void copyArray(const int *sourceArray, int *destinationArray, int size)
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
    for (int i = 0; i < numFunc; i++)
        avg[i] = 0;

    int *testingArray = allocateArray(count);
    int *testingArrayCopy = allocateArray(count);
    if (testingArray == NULL || testingArrayCopy == NULL)
    {
        printf("Error: Couldn't create testing arrays, aborting.\n");
        return;
    }

    for (int i = 0; i < nIter; i++)
    {
        generateUniqueRandIntegers(testingArray, min, max, count);
        copyArray(testingArray, testingArrayCopy, count);

        for (int j = 0; j < numFunc; j++)
        {
            clock_t start_time = clock();
            sort[j](testingArrayCopy, count);
            clock_t end_time = clock();

            double sorting_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            avg[j] += sorting_time / nIter;

            // Verify the sorted array & print the results
            if (isSorted(testingArrayCopy, count))
            {
                printf("Sorting Time of %s : %lf\n", sortFuncNames[j], sorting_time);
            }
            else
            {
                printf("ERROR: Array was not sorted correctly.\n");
            }

            // Recopy the testingArray to the now sorted testingArrayCopy
            copyArray(testingArray, testingArrayCopy, count);
        }
    }

    for (int i = 0; i < numFunc; i++)
    {
        printf("The average sorting time of %s : %f\n", sortFuncNames[i], avg[i]);
    }

    // Free the dynamically allocated memory
    free(testingArray);
    free(testingArrayCopy);
}
