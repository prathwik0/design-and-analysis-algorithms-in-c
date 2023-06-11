#include "test.h"

int search(int *array, int n, int element)
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
    test();
    return 0;
}
