#include <stdio.h>
#include <stdlib.h>

int no_res, no_pro, max_need[10][10], alloc[10][10], needed[10][10], avail_res[10], max_res[10], count, visited[100];
void printMatrix(int a[10][10])
{
    for (int i = 0; i < no_pro; i++)
    {
        for (int j = 0; j < no_res; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
}

void printArray(int a[10])
{
    for (int i = 0; i < no_res; i++)
    {
        printf("%d", a[i]);
    }
}

int main()
{
    printf("Enter no. of resources:");
    scanf("%d", &no_res);
    printf("Enter no. of processes:");
    scanf("%d", &no_pro);

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < no_pro; i++)
        for (int j = 0; j < no_res; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Need Matrix:\n");
    for (int i = 0; i < no_pro; i++)
        for (int j = 0; j < no_res; j++)
            scanf("%d", &max_need[i][j]);

    for (int i = 0; i < no_pro; i++)
        for (int j = 0; j < no_res; j++)
            needed[i][j] = max_need[i][j] - alloc[i][j];

    printf("Enter Max process:");
    for (int i = 0; i < no_res; i++)
        scanf("%d", &max_res[i]);

    printf("Enter Available Resources:");
    for (int i = 0; i < no_res; i++)
        scanf("%d", avail_res[i]);

    // BANKER
    int flag = 0, finish[100], safeSequence[100], c = 0;
    for (int i = 0; i < no_pro; i++)
    {
        finish[i] = 0;
    }
    for (int y = 0; y < no_pro; y++)
    {
        for (int i = 0; i < no_pro; i++)
        {
            if (finish[i] == 0)
            {
                for (int j = 0; j < no_res; j++)
                {
                    if (needed[i][j] > avail_res[j])
                    {
                        flag++;
                        break;
                    }
                }
                if (flag == 0)
                {
                    finish[i] = 1;
                    for (int k = 0; k < no_res; k++)
                    {
                        avail_res[k] += alloc[i][k];
                    }
                    safeSequence[c] = i;
                    c++;
                }
            }
        }
        flag = 0;
        for (int i = 0; i < no_pro; i++)
        {
            if (!finish[i])
            {
                flag++;
                break;
            }
        }
        if (!flag)
        {
            printf("The system is in SAFE STATE\nSAFE SEQUENCE:\n");
            for (int j = 0; j < no_pro; j++)
                printf("%d", safeSequence[j]);
        }
        else
        {
            printf("The system is NOT in SAFE STATE");
        }
    }
}

/*ALLOC:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
*/

/*MAX:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
*/
// cd "c:\Users\Seon\Desktop\PRACS CODE\OS\" ; if ($?) { g++ DEADLOCK.C -o DEADLOCK } ; if ($?) { .\DEADLOCK }