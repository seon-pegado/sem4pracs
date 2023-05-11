#include<stdio.h>
int np, nr, aloc[10][10], max[10][10], need[10][10], mres[10], avres[10], alres[10];
// mres->maximum resource avres->available res. alres->allocated res.
void readmatrix(int mat[10][10]){
    for(int i = 0 ; i<np ; i++){
        for(int j=0 ; j<nr ; j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void calculateneed(){
    for(int i = 0 ; i<np ; i++){
        for(int j=0 ; j<nr ; j++){
            need[i][j] = max[i][j] - aloc[i][j];
        }
    }
}

void printmatrix(int mat[10][10]){
    for(int i = 0 ; i<np ; i++){
        for(int j=0 ; j<nr ; j++){
            printf("%d",&mat[i][j]);
        }
        printf("\n");
    }
}


int  main(){
    for(int i=0 ; i<nr ; i++){
        alres[i] = 0;
    }
    printf("Enter the number of process and resource:");
    scanf("%d",&np, &nr);
    
    printf("Enter the Allocation matrix :");
    for(int i = 0 ; i<np ; i++){
        for(int j=0 ; j<nr ; j++){
            scanf("%d",&aloc[i][j]);
        }
    }

    printf("Enter the Maximum resource needed by process matrix:");
    readmatrix(max);

    printf("The need matrix is:");
    printmatrix(need);

    printf("Enter the maximum no. of available resource:");
    for(int i=0 ; i<nr ; i++){
        scanf("%d",&mres[i]);
    }

    for(int i=0 ; i<np ; i++){
        for(int j=0 ; j<nr ; j++){
            alres[j] += aloc[i][j];//gives total allocated resource
        }

    }
    for(int i=0 ; i<nr ; i++){
        avres[i] = mres[i] - alres[i];
    }
    for(int i=0 ; i<nr ; i++){
        printf("%d",&avres[i]);
    }


    




   return 0;

}