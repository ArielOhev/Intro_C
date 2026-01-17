#include <stdio.h>

void Selection_Sort(int *arr,int n);
void PrintArr(int *arr,int n);

int main(){
    int arr[]={1,2,0,-1,7,9};
    int n= sizeof(arr)/sizeof(arr[0]);
    PrintArr(arr,n);
    Selection_Sort(arr,n);
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
void Selection_Sort(int *arr,int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}