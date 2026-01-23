#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define R 3
#define C 5



int main(){
    return 0;
}

int quest3(int *a,int n){
    int *count=(int*)calloc(n,sizeof(int));
    for(int i=0;i<n;i++){
        if(a[i]<=n-1) count[a[i]]++;
    }
    int count_num=0;
    for(int i=0;i<n;i++){
        if(count[i]>0) count_num++;
    }
    return count_num;
}
int quest4(int *a,int *b,int n){
    int index=n+1;
    for(int i=0;i<n;i++){
        if(a[0]==b[i]) index=i;
    }
    if(index>n) return 0;

    for(int i=0;i<n-index;i++){
        if(a[i]!=b[i+index]) return 0;
    }
    for(int i=0;i<index;i++){
        if(b[i]!=a[n-index+i]) return 0;
    }
    return 1;
}
void quest5(int *arr,int n){
    int index=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            index=i;
        }
    }
    int *tmp=(int*)calloc(n,sizeof(int));
    assert(tmp);
    int *reader1= arr;
    int *reader2=arr+index+1;
    for(int i=0;i<n;i++){
        if(*reader1>*reader2) tmp[i]=*(reader2++);
        else tmp[i]=*(reader1++);
    }
    for(int i=0;i<n;i++){
        arr[i]=tmp[i];
    }

    free(tmp);
}
