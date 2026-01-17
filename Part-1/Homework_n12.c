#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void mergesort(int *arr,int n);
void merge(int *left,int nL,int *right,int nR,int *arr,int n);

void PrintArr(int *arr,int n);
void quest1(int *A,int k);
void quest2(int *arr,int n);
void quest3(int *arr,int n);
void quest4(int *arr,int n);

void quest6(int *A,int n);
int quest7(int *arr1,int *arr2,int n);
int quest8(int *arr,int n);
void quest9(int *arr,int n,int *k,int *j);
int* quest10(int *arr,int n,int k);

int main(){
    int arr1[]={1,7,-1,3,2};
    int n=sizeof(arr1)/sizeof(arr1[0]);
    int k=3;
    int *ptr;
    PrintArr(arr1,n);
    ptr=quest10(arr1,n,k);
    PrintArr(ptr,k);
    free(ptr);

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

void quest1(int *A,int k){
    for(int i=0;i<k;i+=2){
        if(A[i]>A[i+1]){
            swap(&A[i],&A[i+1]);
        }
    }
}
void quest2(int *arr,int n){
    int ones_I=0;
    int twos_I=n-1;

    for(int i=0;i<n;i++){
        if(arr[i]==0) swap(&arr[ones_I++],&arr[i++]);
        if(arr[i]==2) swap(&arr[twos_I--],&arr[i++]);
        PrintArr(arr,n);
    }
}
void quest3(int *arr,int n){
    int *A=(int*)calloc((n+1),sizeof(int));
    assert(A);
    for(int i=0;i<n;i++){
        A[arr[i]]++;
    }
    int i=0;
    for(int j=0;j<n+1;j++){
        if(A[j]>0){
            while (A[j]>0)
            {
                arr[i++]=j;
                A[j]--;
            }
        }
    }
    free(A);
}
void quest4(int *arr,int n){
    int high=n-1;
    int low=0;

    for(int i=0;i<n;i++){
        if(arr[i]>0)swap(&arr[i],&arr[low++]);
        else swap(&arr[i],&arr[high--]);
    }
}

void quest6(int *A,int n){
    int low=0,i=0;
    int high=n-1;

    while(i<=high){
        if(A[i]%3==0) swap(&A[i++],&A[low++]);
        else if(A[i]%3==2) swap(&A[i],&A[high--]);
        else i++;
    }
}
int quest7(int *arr1,int *arr2,int n){
    mergesort(arr1,n);
    mergesort(arr2,n);
    for(int i=0;i<n;i++){
        if(arr1[i]!=arr2[i]) return 0;
    }
    return 1;
}
int quest8(int *arr,int n){
    mergesort(arr,n);
    int sum=0;

    for(int i=0;i<n;i++){
        if(arr[i]==sum) return arr[i];
        sum+=arr[i];
    }
    return -1;
}
void quest9(int *arr,int n,int *k,int *j){
    mergesort(arr,n);
    int min_sum=arr[1]-arr[0];
    *k=arr[0];
    *j=arr[1];

    for(int i=1;i<n-1;i++){
        if(arr[i+1]-arr[i]<min_sum){
            *k=arr[i];
            *j=arr[i+1];
            min_sum=arr[i+1]-arr[i];
        }
    }

}

int* quest10(int *arr,int n,int k){
    int *newArr=(int*)malloc(k*sizeof(arr[0]));
    assert(newArr);
    mergesort(arr,n);
    
    for(int i=0;i<k;i++){
        newArr[i]=arr[i];
    }
    return newArr;
}


































































