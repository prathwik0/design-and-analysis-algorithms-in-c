static void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

static int partition(int *arr, int l, int h)
{
    int pivot = l, i = l, j = h + 1;
    do
    {
        do
        {
            i++;
        } while (i < h && arr[i] <= arr[pivot]);
        do
        {
            j--;
        } while (j > l && arr[j] >= arr[pivot]);
        swap(arr + i, arr + j);
    } while (i < j);

    swap(arr + i, arr + j);
    swap(arr + pivot, arr + j);

    return j;
}

static void quickSortMain(int *arr, int l, int h)
{
    if (l >= h)
        return;

    int s = partition(arr, l, h);
    quickSortMain(arr, l, s - 1);
    quickSortMain(arr, s + 1, h);
}

void quickSort(int *arr, int n)
{
    quickSortMain(arr, 0, n - 1);
}
