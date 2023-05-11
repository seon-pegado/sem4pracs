#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int c[100][100],m,n;
char x[100], y[100], b[100][100];

void print(int i , int j){
    if(i==0||j==0)
     return;
    if(b[i][j] == 'c'){
        print(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j] == 'u'){
        print(i-1,j);
    }
    else{
        print(i,j-1);
    }

}

void LCS(){
    m = strlen(x);
    n = strlen(y);
    for(int i=0 ; i<=m ; i++)
       c[i][0] = 0;
    for(int i=0 ; i<=n ; i++)
       c[0][i] = 0;
    
    for(int i=1 ; i<=m ; i++){
        for(int j=1 ; j<=n ; j++){
            if(x[i-1]==y[j-1]){
                c[i][j] = c[i-1][j-1] +1;
                b[i][j] = 'c';
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 'u';
            }
            else{
               c[i][j] = c[i][j-1];
               b[i][j] = 'l';
            } 
        }
    }
}

void main()
{
    printf("Enter the 1st Sequence:");
    scanf("%s",&x);
    printf("Enter the 2nd Sequence:");
    scanf("%s",&y);
    printf("The LCS is:");
    LCS();
    print(m,n);
}