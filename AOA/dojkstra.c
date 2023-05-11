#include <stdio.h>
#include <stdlib.h>
int cost[100][100], n, s, d[100];

void Dijkstra()
{
    int visited[100], min, v, count = 1;
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
        d[i] = cost[s][i];
    }
    visited[s] = 1;
    d[s] = 0;
    while (count < n)
    {
        for (int i = 0, min = 999; i < n; i++)
        {
            if (d[i] < min&&visited[i]==0)
            {
                min = d[i];
                v = i;
            }
        }

        visited[v] = 1;
        for (int i = 0; i < n; i++)
        {
           if (d[i] > d[v] + cost[v][i])
                d[i] = d[v] + cost[v][i];
        }
        count++;
    }
    for(int i=0 ; i<n  ;i++){
        printf("%d\t",d[i]);
    }
}
// 0 2 6 0 0 0 0 
// 2 0 0 5 0 0 0
// 6 0 0 8 0 0 0
// 0 5 8 0 10 15 0
// 0 0 0 10 0 0 2
// 0 0 0 15 0 0 6
// 0 0 0 0 2 6 0
void main()
{
    printf("Enter the number of nodes:");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
                cost[i][j] = 999;
        }

    printf("Enter the Starting node");
    scanf("%d", &s);

    Dijkstra();
}