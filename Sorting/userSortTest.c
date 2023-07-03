#include "bubbleSort.h"
#include "insertionSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "selectionSort.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, arr[10];
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);

    quickSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}