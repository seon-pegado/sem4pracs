#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int m,n;

void prefixArray(int n, char *pat, int *pa)
{
    int length = 0;
    pa[0] =0 ;
    int i=1;
    while(i<n){
        if(pat[i] == pat[length]){
            length++;
            pa[i] = length;
            i++;
        }
        else if(length != 0)
            length = pa[length -1];
        else  
        {
            pa[i] = 0;
            i++;
        }
    }

}

void KMP(char *text, char *pat)
{
    m = strlen(text);
    n = strlen(pat);
    int pa[n];
    prefixArray(n, pat, pa);
    int i=0,j=0;
    while(i<m){
        if(pat[j] == text[i]){
            i++;
            j++;
        }
        if(j==n){
            printf("The pattern found at at index:%d\n",i-j);
            j = pa[j-1];
        }
        else if(i<m && pat[j] != text[i]){
            if(j!=0)
                j = pa[j-1];
            else 
                i = i+1;
        }
    }
    
}

void main()
{
    char text[] = "xyztrwqxyzfg";
    char pat[] = "xyz";
    KMP(text, pat);

}