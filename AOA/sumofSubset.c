#include<stdio.h>
#include<stdlib.h>
int w[100], n, x[100], m;

void SumofSubset(int k, int s, int r)
{
    x[k] =1;
    if(s+w[k] == m){
        for(int i=0 ; i<n ; i++){
            printf("%d",x[i]);
        }
        printf("\n");
    }
    else if(s+ w[k] + w[k+1]<= m){
        SumofSubset(k+1, s+w[k], r-w[k]);
    }
    if(s+r-w[k] >= m && s + w[k+1]<= m){
        x[k] =0;
        SumofSubset(k+1, s, r-w[k]);
    }

}

void main()
{
    int t=0;
    printf("Enter the size of array:");
    scanf("%d",&n);
    printf("Enter the element:\n");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&w[i]);
        t += w[i];
        x[i] = 0;
    }
    printf("Sum:");
    scanf("%d",&m);
    SumofSubset(0,0,t);

}