// C program to perform linear search on a dynamic array of integers
#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *array, int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] == element)
            return i;
    }
    return -1;
}

int main()
{
    int n, element;
    printf("Enter n: ");
    scanf("%d", &n);

    int *array = (int *)malloc(sizeof(int) * n);
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", array + i);

    printf("Enter element to search: ");
    scanf("%d", &element);

    int pos = linearSearch(array, n, element);
    if (pos < 0)
        printf("Element not present in the array\n");
    else
        printf("Element found at position %d\n", pos);

    free(array);
    return 0;
}
