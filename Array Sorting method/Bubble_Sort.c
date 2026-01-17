#include <stdio.h>

void Bubble_Sort(int *arr,int n);
void PrintArr(int *arr,int n);

int main(){
    int arr[]={1,2,0,-1,7,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    PrintArr(arr,n);
    Bubble_Sort(arr,n);
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

void Bubble_Sort(int *arr,int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}