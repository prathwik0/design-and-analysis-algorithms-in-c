#include <stdio.h>

void toh(int n, int a, int b, int c)
{
    if (n == 0)
        return;
    toh(n - 1, a, c, b);
    printf("Move a disk from rod %d to rod %d\n", a, c);
    toh(n - 1, b, a, c);
}

int main()
{
    int n = 3;
    toh(n, 1, 2, 3);
    return 0;
}