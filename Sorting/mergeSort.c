static void merge(int *left, int sizeLeft, int *right, int sizeRight, int *arr)
{
    int i = 0, j = 0, k = 0;
    while (i < sizeLeft && j < sizeRight)
    {
        if (left[i] < right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    /*Copy any remaining elements in the arrays*/
    for (; i < sizeLeft; i++)
        arr[k++] = left[i];

    /*The below for loop is not required for mergeSortMain*/
    // for (; j < sizeRight; j++)
    //     arr[k++] = right[j];
}

static void mergeSortMain(int *arr, int l, int h)
{
    if (l >= h)
        return;

    int mid = (l + h) / 2;

    mergeSortMain(arr, l, mid);
    mergeSortMain(arr, mid + 1, h);

    int tempSize = mid - l + 1;
    int temp[tempSize];
    for (int i = 0; i < tempSize; i++)
        temp[i] = arr[l + i];

    merge(temp, tempSize, arr + mid + 1, h - mid, arr + l);
}

void mergeSort(int *arr, int n)
{
    mergeSortMain(arr, 0, n - 1);
}
