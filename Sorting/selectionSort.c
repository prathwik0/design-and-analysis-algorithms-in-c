static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int n)
{
    int i, j, min_index;

    for (i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        if (min_index != i)
            swap(arr + min_index, arr + i);
    }
}
