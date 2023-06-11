/* Simple C program to multiply 2 compatible matrices of maximum size 10x10 */
#include <stdio.h>

void input(int a[][10], int m, int n)
{
    printf("\nEnter elements: \n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
}

void multiply(int a[][10], int b[][10], int c[][10], int m1, int n1, int m2, int n2)
{
    for (int i = 0; i < m1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            c[i][j] = 0;
            for (int k = 0; k < n1; ++k)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void display(int a[][10], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int a[10][10], b[10][10], c[10][10], m1, m2, n1, n2;
    printf("Enter rows and column for the first matrix: ");
    scanf("%d %d", &m1, &n1);
    printf("Enter rows and column for the second matrix: ");
    scanf("%d %d", &m2, &n2);

    if (m1 != n2)
    {
        printf("Matrices are not compatible\n");
        return 0;
    }

    input(a, m1, n1);
    display(a, m1, n1);
    input(b, m2, n2);
    display(b, m2, n2);

    multiply(a, b, c, m1, n1, m2, n2);
    printf("\n\nResult is: \n");
    display(c, m1, n2);

    return 0;
}
