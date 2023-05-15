#include<stdio.h>
#include<stdlib.h>

int block[100], process[100], m, n;

void bestfit()
{
    int alloc[100];
    for(int i=0 ; i<n ; i++)
        alloc[i] = -1;
    for(int i=0 ; i<n ; i++){
        int worstIdx=-1;
        for(int j=0 ; j<m ; j++){
            if(block[j] >= process[i]){
                if(worstIdx == -1)
                   worstIdx = j;
                else if(block[worstIdx] < block[j])
                   worstIdx = j;
            }
        }

        if(worstIdx != -1){
            alloc[i] = worstIdx;
            block[worstIdx] -= process[i];
        }
    }
    printf("Process No.\tProcess Size\tBlock No.\n");
    for(int i=0 ; i<n ; i++){
        printf("%d\t\t%d\t\t",i+1,process[i]);
        if(alloc[i] != -1 ){
            printf("%d",alloc[i]+1);
        }
        else{
            printf("Not Allocated");
        }
        printf("\n");
    }
}

void main(){
    printf("Enter the no. of blocks:");
    scanf("%d",&m);
    printf("Enter the size of Blocks:\n");
    for(int i=0 ; i<m ; i++)
        scanf("%d",&block[i]);
    printf("Enter the no. of processes:");
    scanf("%d",&n);
    for(int i=0 ; i<n ; i++)
        scanf("%d",&process[i]);

    bestfit();
}

