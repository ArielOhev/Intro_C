#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define N 3


void merge(int *left,int nL,int *right,int nR,int *arr,int n);
void mergesort(int *arr,int n);
void swap(int *a,int *b);
void PrintArr(int *arr,int n);

int quest1(int dig,int n);
int quest2A(int *a,int *b,int n,int d);
int quest2B(int *a,int *b,int n,int d);
int quest3();

int main(){
    int a[]={12,2,14,2};
    int b[]={15,11,2,8};

    printf("%d\n",quest3());

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


int quest1(int dig,int n){
    if(dig<10){
        if(dig==n) return 0;
        else return dig;
    };

    int num=dig%10;

    if(num!=n){
        return (quest1(dig/10,n)*10)+num;
    }
    else{
        return quest1(dig/10,n);
    }
}

int quest2A(int *a,int *b,int n,int d){
    mergesort(a,n);

    int high=n-1;
    int low=0;
    int mid;

    for(int i=0;i<n;i++){
        high=n-1;
        low=0;
        while (low<=high)
        {
            mid=(low+high)/2;
            if(b[i]+d==a[mid]) return 1;
            if(b[i]+d>a[mid]) low=mid+1;
            else high=mid-1;
        }
    }
    return 0;
}

int quest2B(int *a,int *b,int n,int d){
    mergesort(a,n);
    mergesort(b,n);
    int *tmp1,*tmp2;
    tmp1=a;
    tmp2=b;
    

    int i=0,j=0;
    while(i<n && j<n){
        if(*tmp1==*tmp2+d) return 1;
        if(*tmp1>*tmp2+d){
            tmp2++;
            j++;
        } 
        else{
            tmp1++;
            i++;
        } 

    }
    
    return 0;
}

int quest3(){
    int num;
    // scanf("%d",&num);
    int count=0;
    int countZero=0;

    while (num!=-1)
    {
        scanf("%d",&num);
        if(num!=-1) count++;
        if(num==0){
            count=0;
            countZero++;
        }
    }
    if(countZero==0) return -1;
    return count;
    
}

int countNum(int a[N][N],int n){
    int count=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i][j]==n) count++;
        }
    }
    return count;
}

int quest4(int a[N][N]){
    for(int i=1;i<((N*N)+1);i++){
        if(countNum(a,i)!=1) return 0; 
    }

    return 1;

}

int quest4B(int a[N][N]){
    int *tmp = (int*) calloc (N*N+1,sizeof(int));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            tmp[a[i][j]]++;
        }
    }

    for(int i=1;i<N*N+1;i++){
        if(tmp[i]!=1) return 0;
    }
    return 1;
}

double quest5(int x,int n){
    double sum=0;
    double num;
    double num_x=1;
    for(int i=1;i<n;i++){
        num_x*=x;
        num=num_x/i;
        if(i%2!=0){
            sum+=num;
        }

    }
    return sum;

}




