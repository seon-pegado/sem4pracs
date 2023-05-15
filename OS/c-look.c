#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int track, no_req, req[100], Head, Head1, distance=0, finish[100], pending;
int choice;

void LOOKRIGHT(){
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
    int i=0;
    while( i< index){
        distance += abs(req[i] - Head1);
        printf("%d=>",req[i]);
        Head1 = req[i];
        i++;
    }
    printf("End\n\n");
    printf("the total seek time is:%d",distance);
}

void LOOKLEFT(){
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
    index++;
    int i=no_req -1;
    while(i>=index){
        distance += abs(req[i] - Head1);
        printf("%d=>",req[i]);
        Head1 = req[i];
        i--;
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
        LOOKRIGHT();
    else
        LOOKLEFT();



}