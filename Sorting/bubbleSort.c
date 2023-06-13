static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Here having the swapped variable increases the best case efficiency to n
void bubbleSort(int *arr, int n)
{
    int i, j, swapped = 0;

    for (i = 0; i < n - 1; i++)
    {
        swapped = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr + j, arr + j + 1);
                swapped = 1;
            }
        }

        if (swapped == 0)
            break;
    }
}
