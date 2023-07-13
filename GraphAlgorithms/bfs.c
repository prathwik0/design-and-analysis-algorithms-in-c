/*
 * Write a program to print all the nodes reachable from a given
 * starting node in a digraph using BFS method and determine
 * the time required.
 */

#include <stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v)
{
    for (i = 1; i <= n; i++)
        if (a[v][i] && !visited[i])
            q[++r] = i;

    if (f <= r)
    {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}

int main()
{
    int v;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }

    printf("Enter graph data in matrix form:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);
    bfs(v);

    printf("\nThe nodes which are reachable are:\n");
    for (i = 1; i <= n; i++)
        if (visited[i])
            printf("%d\t", i);
        else
            printf("\nBfs is not possible");

    return 0;
}