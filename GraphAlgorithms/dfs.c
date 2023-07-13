/*
 * Check whether a given graph is connected or not
 * using DFS method and determine the time required.
 */

#include <stdio.h>

int a[20][20], reach[20], n;

void dfs(int v)
{
    int i;
    reach[v] = 1;

    for (i = 1; i <= n; i++)
        if (a[v][i] && !reach[i])
        {
            printf("\n%d->%d", v, i);
            dfs(i);
        }
}

int main()
{
    int i, j, count = 0;

    printf("\nEnter no of vertices : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            reach[i] = 0;
            a[i][j] = 0;
        }

    printf("\nEnter adjacency matrix : \n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    dfs(1);

    for (i = 1; i <= n; i++)
        if (reach[i])
            count++;

    if (count == n)
        printf("\nGraph is connected.");
    else
        printf("\nGraph is disconnected.");

    return 0;
}