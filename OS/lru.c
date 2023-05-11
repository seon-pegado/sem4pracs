#include<stdio.h>
#include<stdlib.h>

int no_pages, no_frames, pages[100], frames[100], hit=0, count[100];

void print(){
    for(int i=0 ; i<no_frames ; i++){
        printf("%d\t",frames[i]);
    }
    printf("\n");
}

int minIndex(){
    int index = 0;
    for(int i=1 ; i<no_frames ; i++){
        if(count[i]<count[index])
            index = i;    
    }

    return index;
}

void LRU()
{
    frames[0] = pages[0];
    count[0] = 0;
    int k=1;
    for(int i=1 ; i<no_pages ; i++){
        int c = 0, j;
        for(j=0 ; j<k ; j++){
            if(frames[j] != pages[i]){
                c++;
            }
            else
               goto lru;

        }
        
        if(c==k && k< no_frames){
            frames[i] = pages[i];
            count[i] = i;
            k++;
            print(); 
        }

        else if(c==k && k>= no_frames){
            int index = minIndex();
            // printf("%d",index);
            frames[index] = pages[i];
            count[index] = i;
            print();   
        }

        else{
            lru:
            hit++;
            count[j] = i;
            print();
            
        }       
    }
}

int  main()
{
    printf("Enter the no. of pages:");
    scanf("%d",&no_pages);
    printf("Enter the no. of frames:");
    scanf("%d",&no_frames);
    printf("Enter the the refernced pages:\n");
    for(int i=0 ; i<no_pages ; i++){
        scanf("%d",&pages[i]);
    }

    LRU();

    printf("HIT :%d",hit);
    printf("FAULT :%d",(no_pages - hit));
}