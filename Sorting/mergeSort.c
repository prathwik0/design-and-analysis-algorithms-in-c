#include <stdio.h>
#include <stdlib.h>

static void merge(int *A, int sizeA, int *B, int sizeB, int *arr)
{
    int i = 0, j = 0, k = 0;
    while (i < sizeA && j < sizeB)
    {
        if (A[i] < B[j])
        {
            arr[k] = A[i];
            i++;
        }
        else
        {
            arr[k] = B[j];
            j++;
        }
        k++;
    }
    /*Copy any remaining elements in the arrays*/
    for (; i < sizeA; i++)
    {
        arr[k++] = A[i];
    }
    for (; j < sizeB; j++)
    {
        arr[k++] = B[j];
    }
}

void mergeSort(int *arr, int n)
{
    if (n <= 1)
        return;

    int *A = (int *)malloc(sizeof(int) * (n / 2));
    int *B = (int *)malloc(sizeof(int) * ((n + 1) / 2));
    if (A == NULL || B == NULL)
    {
        printf("Error: couldn't allocate memory using malloc.");
        exit(0);
    }

    int i = 0;
    for (; i < (n / 2); i++)
    {
        A[i] = arr[i];
    }
    for (int j = 0; i < n; i++, j++)
    {
        B[j] = arr[i];
    }
    mergeSort(A, n / 2);
    mergeSort(B, (n + 1) / 2);
    merge(A, n / 2, B, (n + 1) / 2, arr);
}
