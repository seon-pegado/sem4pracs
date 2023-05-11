#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int track, no_req, req[100], Head, Head1, distance, finish[100], pending;

void SSTF(){
    int min , diff, index;
    Head1 = Head;
    pending = no_req;
    distance = 0 ;
    for(int i=0 ; i<no_req ; i++){
        finish[i] = 0;
    }
    printf("%d=>",Head);
    while(pending>0){
        min = 9999999;
        for(int i=0 ; i<no_req ; i++){
            diff = abs(req[i] - Head1);
            if(finish[i] == 0 && diff<min){
                min = diff;
                index = i;
            }
        }
        finish[index] = 1;
        distance += abs(req[index] - Head1);
        Head1 = req[index];
        pending--;
        printf("%d=>",Head1);
        
    }
    printf("End");
    printf("The Distance is:%d",distance);
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

    SSTF();

}