#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define N 4

int main(){
    return 0;
}

int quest1(int n){
    if(n<100) return 1;

    int first = n%1000;
    int second = n%100;
    int third = n%10;
    if(first>second && second<third){
        return quest1(n/1000)%2;
    }
    return 0;
}

int quest2(int *a,int n,int x){
    int high=n-1;
    int low=0;
    int mid;

    while (low<high)
    {
        mid=(high+low)/2;
        if(a[mid]+a[mid+1]==x) return n;
        else if (a[mid]+a[mid+1]>x)
        {
            high=mid;
        }
        else low=mid+1;
    }
    return -1;
}

int quest3A(int *arr,int n){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) count=0;
        else{
            count++;
            arr[i]=count;
        } 
    }
}

int quest3B(int *arr,int n){
    int count=0;
    int count_zero=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count=0;
            count_zero++;
        }
        else if(arr[i]!=0 && count_zero==0){
            arr[i]=1;
        }
        else{
            count++;
            arr[i]=count;
        } 
    }
    count=0;
    for(int i=n-1;i>=0;i--){
        count++;
        if(arr[i]==0){
            count=0;
            count_zero--;
        } 
        if(arr[i]>count && count_zero!=0){
            arr[i]=count;
        }
        if(count_zero==0) arr[i]=count;
    }
}

int quest4(char *str){
    int num=0;;
    int pow=1;
    int neg=0;
    if(*str=='-'){
        neg=1;
        str++;
    }

    while (*str!='\0')
    {
        num+=pow*(*str-'0');
        pow*=10;
        str++;
    }
    if(neg) return num*-1;
    return num;
}

int quest5(int mat[N][N]){
    int count;
    int maxCount=0;
    for(int i=0;i<N;i++){
        count=0;
        for(int j=1;j<N;j++){
            if(mat[j][i]>mat[j-1][i]) count++;
        }
        if(count>maxCount)maxCount=count;
    }
    return maxCount;
}























































