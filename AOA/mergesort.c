#include<stdio.h>
#include<stdlib.h>

int a[100], n;

void print()
{
    for(int i=0 ; i<n ; i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void Merge(int low, int mid, int high){
    int t[100];
    int i = low, k = 0, j = mid+1;
    while(i<=mid && j<=high){
        if(a[i] > a[j])
            t[k++] = a[j++];
        else
            t[k++] = a[i++];
    }
    while(i<=mid)
      t[k++] = a[i++];
    while(j<=high)
      t[k++] = a[j++];

    for(i=low,j=0 ; i<=high ; i++,j++)
        a[i] = t[j];
}

void MergeSort(int low , int high){
    int m;
    if(low<high){
        m = (low+high)/2;
        MergeSort(low , m);
        MergeSort(m+1 , high);

        Merge(low, m, high);
    }
}

void main(){
    printf("Enter tne no of element:");
    scanf("%d",&n);
    printf("Enter the element:");
    for(int i=0;i<n ; i++){
        scanf("%d",&a[i]);
    }

    MergeSort(0 , n-1);
    print();

}