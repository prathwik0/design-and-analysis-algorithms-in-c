#include "test.h"

int recursiveBinarySearch(int *array, int low, int high, int element)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (array[mid] == element)
        return mid;
    else if (array[mid] > element)
        return recursiveBinarySearch(array, 0, mid - 1, element);
    else
        return recursiveBinarySearch(array, mid + 1, high, element);
}

// Wrapper for recursive binary search
int search(int *array, int n, int element)
{
    return recursiveBinarySearch(array, 0, n - 1, element);
}

int main()
{
    test();
    return 0;
}
