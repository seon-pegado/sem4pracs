#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int track, no_req, req[100], Head, Head1, distance, finish[100], pending;

void FCFS(){
    for(int i=0 ; i<no_req ; i++){
        finish[i] = 0;
    }
    int i=0;
    Head1 = Head;
    int pending = no_req;
    printf("%d=>",Head);
    while(pending>0){
        distance += abs(req[i] - Head1);
        finish[i] = 1;
        Head1 = req[i];
        i++;
        printf("%d=>",Head1);
        pending--;
    }
    printf("End\n");
    printf("The Distance Covered by disk is : %d",distance);

}

void main(){
    printf("Number of Disk:");
    scanf("%d",&track);
    printf("Number of disk request:");
    scanf("%d",&no_req);
    for(int i=0 ; i<no_req ; i++){
        printf("Enter the req:");
        scanf("%d",&req[i]);
    }
    printf("Enter current Head position:");
    scanf("%d",&Head);

    FCFS();

}