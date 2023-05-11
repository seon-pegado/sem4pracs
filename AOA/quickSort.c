#include<stdio.h>
#include<stdlib.h>

int a[100], n;

int partition(int low, int high){
    int i= low+1 ;
    int j=high;
    int temp;
    int pivot = a[low];
    do{
        while(a[i]<=pivot)
           i++;
        while(a[j] > pivot)
           j--;
        if(i<j){
           temp = a[i];
           a[i] = a[j];
           a[j] = temp;
        }
    }while(i<j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;

}

void print()
{
    for(int i=0 ; i<n ; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void quickSort(int low, int high){

    if(low<high){
        int index = partition(low , high);
        quickSort(low, index-1);
        quickSort(index+1, high);
    }
}

void main(){
    printf("Enter the size of array:");
    scanf("%d", &n);
    printf("Enter the elements:");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }
    print();
    quickSort(0,n-1);
    print();
}