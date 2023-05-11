#include<stdio.h>
#include<stdlib.h>

int no_pages, no_frames, pages[100], frames[100], hit=0;

void print(){
    for(int i=0 ; i<no_frames ; i++){
        printf("%d\t",frames[i]);
    }
    printf("\n");
}

void FIFO()
{
    int c =0, count;
    frames[0] = pages[0];
    int k=1;
    for(int i=1 ; i<no_pages ; i++){
        for(int j=0; j<k;j++){
            if(frames[j] != pages[i]){
                printf("hellohii");
                count++;
            }
        }
                printf("\n");

        if(count == k && k< no_frames){
            frames[k] = pages[i];
            printf("hello");
            k++;
        }
        else if(count == k && k>= no_frames){
            frames[c] = pages[i];
            printf("%d",k);
            c = (c+1)%no_frames;
        }
        else{
            hit++;

        }
    }

}

void main()
{
    printf("Enter the no. of pages:");
    scanf("%d",&no_pages);
    printf("Enter the no. of frames:");
    scanf("%d",&no_frames);
    printf("Enter the the refernced pages:\n");
    for(int i=0 ; i<no_pages ; i++){
        scanf("%d",&pages[i]);
    }

    FIFO();

    printf("HIT : %d\n",hit);
    printf("FAULT : %d",(no_pages - hit));

}