#include <stdio.h>

#define N 3

int quest1(int n);
void quest4();
int main(){
    quest4();
    return 0;
}

void swap(int *a,int *b){
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int quest1(int n){
    int leftDigit= (n/10)%10;
    int rightDigit = n%10;
    if(n<100){
        if((leftDigit+rightDigit)%2==1) return 1;
        else return 0;
    }

    if((leftDigit+rightDigit)%2==0) return 0;

    return quest1(n/10);
}
int quest2(int arr[N][N],int key,int low,int high){
    if(low>high) return -1;
    int mid = (high+low)/2;

    if(arr[mid][mid]==key) return mid;
    if(arr[mid][mid]<key) return quest2(arr,key,low,mid);
    else return quest2(arr,key,mid+1,high);
}
int* quest3(int *a,int n,int p){
    int *tmp=a;
    int b;

    for(int i=0;i<n;i++){

        if(a[i]<p){
            b=*tmp;
            *tmp=a[i];
            a[i]=b;
            tmp++;
        }
    }
    if(tmp<a+n) return NULL;
    return tmp;
}
void quest4(){
    for(int i=0;i<=7;i++){
        for(int j=1;j<=8;j++){
            for(int k=2;k<=9;k++){
                if(k>j && j>i){
                    printf("%d %d %d\n",i,j,k);
                }
            }
        }
    }
}
double quest5(double x,int n){
    double sum_lower=1;
    double sum_up=1;
    double pow_X=x;
    double sum=3*pow_X;
    int i_factorial=1;

    for(int i=1;i<=n;i++){
        pow_X*=x;
        sum_up=(2*i+3)*pow_X;
        sum_lower*=(i_factorial+1)*(i_factorial+2);
        sum+=sum_up/sum_lower;
        i_factorial+=2;
    }
    return sum;

}










