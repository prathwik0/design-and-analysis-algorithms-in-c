#include "test.h"

int search(int *array, int n, int element)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (array[mid] == element)
            return mid;
        else if (array[mid] < element)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    test();
    return 0;
}
