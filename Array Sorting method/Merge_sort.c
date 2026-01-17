#include <stdio.h>
#include <stdlib.h>

void mergesort(int *arr,int n);
void merge(int *left,int nL,int *right,int nR,int *arr,int n);
void PrintArr(int *arr,int n);

int main(){
    int arr[]={1,2,0,-1,7,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    PrintArr(arr,n);
    mergesort(arr,n);
    PrintArr(arr,n);
    return 0;
}

void PrintArr(int *arr,int n){
    for(int i=0;i<n-1;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void mergesort(int *arr,int n){
    int mid;
    if(n<=1)return;
    mid=n/2;
    int *leftarray=malloc(mid*sizeof(int));
    int *rightarray=malloc((n-mid)*sizeof(int));
    assert(leftarray);
    assert(rightarray);

    int j=0;
    for(int i=0;i<n;i++){
        if(i<mid) leftarray[i]=arr[i];
        else{
            rightarray[j]=arr[i];
            j++;
        }
    }
    mergesort(leftarray,mid);
    mergesort(rightarray,(n-mid));
    merge(leftarray,mid,rightarray,(n-mid),arr,n);
    free(leftarray);
    free(rightarray);

    
}
void merge(int *left,int nL,int *right,int nR,int *arr,int n){
    int i=0,j=0,k=0;

    while(i<nL && j<nR){
        if(left[i]<=right[j]){
            arr[k]=left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while (i<nL)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while (j<nR)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
}