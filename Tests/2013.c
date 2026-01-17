#include <stdio.h>

#define N 3

int max_sum_two(int *arr,int n);
int quest2(int *arr,int n);
int how_many_seq(int *arr,int n);
int quest4(int arr[N][N]);

int main(){
    int arr[N][N]={{2,4,7},{8,1,4},{9,2,1}};
    // int n= sizeof(arr)/sizeof(arr[0]);
    printf("%d\n",quest4(arr));
    return 0;
}

int max_sum_two(int *arr,int n){
    if(n==2) return arr[0]+arr[1];

    int max;
    int num=arr[n-1]+arr[n-2];

    max=max_sum_two(arr,n-1);
    return max>num ? max :num;
}

int quest2(int *arr,int n){
    int high=n-1;
    int low=1;

    int mid;
    while (low<high)
    {
        mid=(high+low)/2;
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
            return mid;
        }
        if(arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return low;
}

int how_many_seq(int *arr,int n){
    int count=0;

    for(int i=0;i<n;i++){
        if(arr[i]>0 && arr[i+1]>0){
            count++;
            while (arr[i]>0)
            {
                i++;
            }
        }
    }
    return count;
}
    
int quest4(int arr[N][N]){
    int sum=0;
    int sum1;
    for(int k=0;k<N;k++){
        sum+=arr[0][k];
    }

    for(int i=1;i<N;i++){
        sum1=sum;
        for(int j=0;j<N;j++){
            sum1-=arr[i][j];
        }
        if(sum1!=0) return 0;
    }
    return 1;
}

int quest5(int a,int n){
    int sum=1;
    int currnum=1;
    int k;

    for(int i=1;i<=n;i++){
        currnum*=a;

        if(i%2==0){
            sum+=currnum;
        }
        else sum-= currnum;
    }

}


