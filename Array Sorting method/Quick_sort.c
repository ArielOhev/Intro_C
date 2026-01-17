#include <stdio.h>

void Quick_Sort(int *arr,int low,int high);
int Partition(int *arr,int low,int high);
void partition_Even(int *arr,int n);
void PrintArr(int *arr,int n);

int main(){
    int arr[]={8,2,4,7,1,3,9,6,5};
    int n= sizeof(arr)/sizeof(arr[0]);
    PrintArr(arr,n);
    // Quick_Sort(arr,0,n-1);
    partition_Even(arr,n);
    PrintArr(arr,n);
    return 0;
}

void PrintArr(int *arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
int Partition(int *arr,int low,int high){
    int pivot=arr[high];
    int i=low-1,j=0;

    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            swap(&arr[++i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}
void Quick_Sort(int *arr,int low,int high){
    if(low>=high)return;

    int partition = Partition(arr,low,high);
    Quick_Sort(arr,low,partition-1);
    Quick_Sort(arr,partition+1,high);    
}

void partition_Even(int *arr,int n){
    int i=-1;
    for(int j=0;j<n;j++){
        if(arr[j]%2==0){
            swap(&arr[++i],&arr[j]);
        }
    }
}
