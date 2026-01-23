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
    int *countArr=(int*)calloc(n,sizeof(int));

    for(int i=0;i<n;i++){
        countArr[a[i]]++;
    }

    int sum=0;
    for(int i=0;i<n;i++){
        sum+=(countArr[i]/2);
    }

    return sum==(n/2) ? 1 :0;


}

int quest4(int *a,int *b,int n){
    int *tmp_a=a;
    int *tmp_b=b+n;

    while (*tmp_b!=b[0] && *tmp_a!=a[n-1])
    {
        if(*tmp_a==*tmp_b) return 0;
        else if(*tmp_b>*tmp_a) tmp_a++;
        else tmp_b--;
    }
    return 1;
    

}

