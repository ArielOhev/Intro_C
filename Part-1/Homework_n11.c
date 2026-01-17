#include <stdio.h>

int quest1(int *arr,int n);
int quest2(int *arr,int n);
int quest3(int *arr,int k,int key);
int quest4(int *arr,int n,int key);
int quest5(int *arr,int n);
int quest6(int *pos,int *neg,int *n,int *j);
int quest7(int *arr,int n);
int quest8(int *arr,int d,int n);
int quest9(int *arr1,int *arr2,int n);
int quest10(int *arr,int n,int x);

int main(){
    int arr[]={1,6,6,6,6,7,7,8,11,14,22};
    printf("%d\n",quest10(arr,11,6));
    return 0;
}

int quest1(int *arr,int n){
    int num=0;
    for(int i=0;i<n;i++){
        num+=(i-arr[i]);
    }
    return num+n;

}

int quest2(int *arr,int n){
    int high=n-1;
    int low=0;

    int mid;
    while (low<=high)
    {
        mid=(high+low)/2;
        if(arr[mid]==mid){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return low;
    
}

int quest3(int *arr,int k,int key){
    int high = (k*2)-1;
    int low=0;

    int mid,num;

    while (low<=high)
    {
        mid=(high+low)/2;
        num=arr[mid]+arr[mid-1];

        if(num==key){
            return mid/2;
        }
        if(num>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int quest4(int *arr,int n,int key){
    int high=n-1;
    int low=0;
    int mid;
    if (key < arr[0]) return arr[0];
    if (key > arr[n-1]) return arr[n-1];

    while (low<high)
    {
        mid=(low+high)/2;
        if(arr[mid]>key){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }


    if((key-arr[low])>(key-arr[low+1])){
        return arr[low];
    }

    return arr[low+1];
    
}

int quest5(int *arr,int n){
    int high=n-1;
    int low = 0;

    int mid;

    while (low<high)
    {
        mid=(low+high)/2;

        if(arr[mid]<arr[high]){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

int quest6(int *pos,int *neg,int *n,int *j){
    int sum=0;
    int col=*n-1;
    int index=0;
    while (index < *n && col >= 0){
        sum=pos[index]+neg[col];
        if(sum==0){
            *n=index;
            *j=col;
            return 1;
        }
        sum>0?col--:index++;
    }
    *n=-1;
    *j=-1;
    return 0;
}

int quest7(int *arr,int n){
    if(arr[0]==0)return 0;
    if(arr[n-1]==1)return n;

    int high=n-1;
    int low=0;

    int mid;
    while (low<high)
    {
        mid=(low+high)/2;

        if(arr[mid]==0){
            high=mid;
        }
        else{
            low=mid+1;
        }

    }
    return low;
    
}

int quest8(int *arr,int d,int n){
    int high=n-1;
    int low=0;

    int mid=0;
    int sum;
    while (low<high)
    {
        mid=(low+high)/2;
        sum=arr[mid+1]-arr[mid];
        if(sum==d){
            return mid;
        }
        if(sum>d){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int quest9(int *arr1,int *arr2,int n){
    int high=n-1;
    int low=0;
    int mid;
    if(arr1[n-1]==arr2[n-1]) return arr2[n];

    while (low<high)
    {
        mid=(low+high)/2;
        if(arr1[mid]==arr2[mid]){
            low=mid+1;
        }
        else{
            high=mid;
        }
        
    }
    return arr2[low];
}

int quest10(int *arr,int n,int x){
    int high=n-1;
    int low=0;
    int mid;
    int count=0;

    while (low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]>x){
            high=mid-1;
        }
        else{
            if(arr[mid-1])
            if(arr[mid]==x)count++;
            low=mid+1;
        }
    }
    return count;
    
}








































