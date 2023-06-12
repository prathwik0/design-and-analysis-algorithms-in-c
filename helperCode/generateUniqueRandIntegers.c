#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int main()
{
    int min = 1;       // Minimum value
    int max = 1000000; // Maximum value
    int count = 50000; // Number of unique random numbers to generate

    int *randomArray = generateUniqueRandIntegers(min, max, count);
    if (randomArray != NULL)
    {
        printf("Generated unique random numbers:\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d\n", randomArray[i]);
        }
        free(randomArray);
    }

    return 0;
}
