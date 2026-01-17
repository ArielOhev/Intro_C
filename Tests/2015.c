#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define N 3

void PrintArr(int *arr,int n);
void swap(int *a,int *b);
void mergesort(int *arr,int n);
void merge(int *left,int nL,int *right,int nR,int *arr,int n);
int quest1(int n);
int quest2(int *arr,int n);
int quest3(char *s1,char*s2);

int main(){
    int arr[]={17,5,9,13,3,20};
    int n=sizeof(arr)/sizeof(arr[0]);

    char s1[]="abcacac";
    char s2[]="bcacac";
    printf("%d\n",quest3(s1,s2));
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

int quest1(int n){
    if(n<=0){
        return 0;
    }

    int num=n%100;
    int x = ((num%10)*10)+num/10;
    return (quest1(n/100)*100)+x;
}

int quest2(int *arr,int n){
    mergesort(arr,n);

    int low=arr[1]-arr[0];
    int currnum;
    for(int i=1;i<n-1;i++){
        currnum=arr[i+1]-arr[i];
        if(low>currnum) low=currnum;
    }
    return low;
}

int quest3(char *s1,char*s2){
    int *countS2 = (int*)calloc(256,sizeof(int));

    int i=0;
    while (s2[i]!='\0')
    {
        countS2[s2[i]]++;
        i++;
    }

    i=0;
    while (s1[i]!='\0')
    {
        if(countS2[s1[i]]>0) countS2[s1[i]]--;
        i++;
    }
    for(i=0;i<256;i++){
        if(countS2[i]>0) return 0;
    }
    return 1;
}
int quest4(int arr[N][N]){
    int min=arr[N-1][0];

    int j;
    for(int i=0;i<N;i++){
        j=0;
        while (i!=j)
        {
            if(arr[i][j]<min) min=arr[i][j];
            j++;
        }
    }
    return min;

}

double quest5(int x,int n){
    int sum_up=x;
    int sum_under=1;
    double sum= sum_up/sum_under;
    double currNum;

    for(int i=1;i<=n;i++){
        sum_up*= (x*x);
        sum_under*=((2*i)+1);
        currNum = sum_up/sum_under;
        sum+=currNum;

    }
    return sum;
}












































