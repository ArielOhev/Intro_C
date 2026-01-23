#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define R 3
#define C 5

int main(){
    return 0;
}

int quest1(int num){
    if(num<10){
        return num;
    }

    int digit=num%10;
    int num = quest1(num/10);
    if(digit>num) return 1;
    else return 0;
}

int quest2(int *a,int *b,int n){
    int high=n-1;
    int low=0;
    int mid;

    while (low<high)
    {
        mid=(high+low)/2;
        if(a[mid]>b[mid]) high=mid;
        else low=mid+1;
    }
    return low;
}

int limit_and_sort(int *a,int n,int m,int *p){
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]<=m)p[a[i]]=a[i];
    }

    int *reader = p;
    int *writer =p;
    int tmp;

    while (reader!=p+m)
    {
        if(*reader>*writer){
            tmp=*reader;
            *reader=*writer;
            *writer=tmp;
            writer++;        
        }
        reader++;
    }
    
}

int checkStr(char *s1,char *s2){
    if(strlen(s1)>strlen(s2)) return 0;
    int flag=1;
    for(int i=0;i<strlen(s1);i++){
        if(s1[i]!=s2[i]) return 0;
    }
    return flag;
}

int quest4(char *s1,char *s2){
    int count=0;
    int *tmp=s2;

    while (*tmp!='\0')
    {
        if(*tmp==s1[0] && checkStr(s1,tmp)) count++;
        tmp++;
    }
    
}

int quest5(int a[R][C],int b[R][C]){
    int max=a[0][0];

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(max<a[i][j]) max=a[i][j];
            b[i][j]=max;
        }
    }

}

















































































