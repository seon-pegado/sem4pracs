#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int track, no_req, req[100], Head, Head1, distance=0, finish[100], pending;
int choice;

void SCANRIGHT(){
    int index=0;
    while(req[index]<= Head)
       index++;
    pending = index;
    Head1 = Head;
    printf("%d=>",Head);
    while(pending < no_req){
        distance += abs(req[pending] - Head1);
        printf("%d=>",req[pending]);
        Head1 = req[pending];
        pending++;
    }
    printf("%d=>",track-1);
    distance += abs(track - Head1 - 1);
    index--;
    Head1 = track-1;
    while(index>=0){
        distance += abs(req[index] - Head1);
        printf("%d=>",req[index]);
        Head1 = req[index];
        index--;
    }
    printf("End\n\n");
    printf("the total seek time is:%d",distance);
}

void SCANLEFT(){
    int index=0;
    while(req[index]<= Head)
       index++;
    index--;
    pending = index;
    Head1 = Head;
    printf("%d=>",Head);
    while(pending>=0){
        distance += abs(req[pending] - Head1);
        printf("%d=>",req[pending]);
        Head1 = req[pending];
        pending--;
    }
    printf("%d=>",0);
    distance += abs(Head1-0);
    index++;
    Head1 = 0;
    while(index < no_req){
        distance += abs(req[index] - Head1);
        printf("%d=>",req[index]);
        Head1 = req[index];
        index++;
    }
    printf("End\n\n");
    printf("the total seek time is:%d",distance);
}
void main(){
        
    printf("Number of Disk:");
    scanf("%d",&track);
    printf("Number of disk request:");
    scanf("%d",&no_req);
    printf("Enter %d request's:",no_req);
    for(int i=0 ; i<no_req ; i++){
        scanf("%d",&req[i]);
    }
    printf("Enter current Head position:");
    scanf("%d",&Head);

    printf("Enter the 0 for Left\nEnter 1 for Right:");
    scanf("%d",&choice);

    if(choice)
        SCANRIGHT();
    else
        SCANLEFT();



}