#include <stdio.h>

int quest2B(int *arr,int n);

int main(){
    int arr[]={1,2,3,4,7};
    printf("%d\n",quest2B(arr,5));    
    return 0;
}

int quest2B(int *arr,int n){
    if(n==0){
        return -1;
    }

    if(arr[n-1]==n-1){
        return n-1;
    }
    return quest2B(arr,n-1);
    
}