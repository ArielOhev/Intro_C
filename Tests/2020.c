#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define R 3
#define C 5



int main(){
    return 0;
}

int quest1(int gematria[26],char *s){
    if(*(s+1)=='\0'){
        return gematria[*s-'a'];
    }
    return quest1(gematria[26],s+1)+gematria[*s-'a'];
}

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

void partition_B(int *A,int n,int* B,int m){
    int i=0,k=0,last=-1;

    while (i<m && k<n)
    {
        if(B[i]==A[k]){
            last++;
            swap(&B[last],&A[k]);
        }

        else{
            if(B[i]>A[k]) k++;
            else i++;
        }

    }
    
}

int quest4(int *arr,int n){
    int high=n-1,low=0,mid;
    
    while (low<high)
    {
        mid=(high+low)/2;
        if(arr[mid]+1!=arr[mid+1]) return arr[mid];
        if(arr[0]+mid==arr[mid]) low=mid+1;
        else high=mid;
    }
    return arr[low];
    
}

void intialize(int *count){
    int i;
    for(i=0;i<10;i++){count[i]=0;}
}

int TestCount(int *count){
    int i;
    for(int i=1;i<10;i++){
        if(count[i]!=1){
            return 0;
        }
    }
    return 1;
}
#define R 6
#define C 5

int soduku(int mat[R][C]){
    int count[10]={0};

    int rows,cols,i,j;

    for(rows=0;rows<R;rows++){
        for(cols=0;cols<C;cols++){
            intialize(count);
            for(i=rows;i<=rows+2;i++){
                for(j=cols;j<=cols+2;j++){
                    count[mat[i][j]]++;
                }
            }
            if (TestCount(count)) return 1;
        }
    }

    return 0;
}


