#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define R 3
#define C 5

int is_even(int num,int dig);
int main(){
    printf("%d\n",is_even(9242,2));
    return 0;
}

int is_even(int num,int dig){
    if(num==0) return 1;

    int n = num%10;
    int i;
    if(n==dig) return is_even(num/10,dig)+1; 
    else return is_even(num/10,dig)-1;
}
int quest2(int *A,int n){
    int *countArr = (int*)calloc(n+1,sizeof(int));

    for(int i=0;i<n;i++){
        countArr[A[i]]++;
    }
    int max=0;

    for(int i=n;i>=0;i--){
        if(countArr[i]==0) return i;
    }

    return -1;

}
void delete_blanks(char *str){
    char *reader=str;
    char *writer=str;

    while (*reader!='\0')
    {
        if(*reader!=' '){
            *writer=*reader;
            writer++;
        }
        reader++;
    }
    *writer='\0';
}
void quest4(int *arr,int *n,int *key){
    int low,high;
    int j=0;
    int i=0;
    while (arr[j]<*key && j<*n)
    {
        j++;
    }
    while (arr[i]>*key && i<*n)
    {
        i++;
    }
    low=arr[i];
    high=arr[j];

    for(int i=0;i<*n;i++){
        if(arr[i]<*key && arr[i]>low){
            low=arr[i];
        }
        if(arr[i]>*key && arr[i]<high){
            high=arr[i];
        }
    }

    if(low<*key && high>*key){
        *n=low;
        *key=high;
    }
    else{
        *n=-1;
        *key=-1;
    }
}
void matrix(int A[R][C],int B[R][C]){
    int sum_col=0;

    for(int i=0;i<R;i++){
        sum_col+=A[i][0];
        B[i][0]=sum_col;
    }

    for(int i=1;i<C;i++){
        sum_col=0;
        for(int j=0;j<R;j++){
            sum_col+=A[j][i];
            B[j][i]=sum_col+B[j][i-1];
        }
    }
}




















