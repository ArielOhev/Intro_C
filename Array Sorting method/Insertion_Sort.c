#include <stdio.h>

void Insertion_Sort(int *arr,int n);
void PrintArr(int *arr,int n);

int main(){
    int arr[]={1,2,0,-1,7,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    PrintArr(arr,n);
    Insertion_Sort(arr,n);
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
void Insertion_Sort(int *arr,int n){
    int tmp;
    for(int i=1;i<n-1;i++){
        tmp=i;
        int j=i-1;
        while (j>=0 && arr[j]>arr[tmp])
        {
            swap(&arr[j+1],&arr[j]);
            j--;
        }
        swap(&arr[j+1],&arr[tmp]);   
    }
}