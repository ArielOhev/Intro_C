#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define R 3
#define N 4



int main(){
    return 0;
}

int quest1(int *a,int n){
    if(n==0) return 1;
    int first=a[0];
    int second=a[1];
    if(second>first) return quest1(a+1,n-1)+1;
    else return ;
}

void removeDuplicates(char *str){
    char *tmp=str;
    int count[26]={0};

    for(int i=0;i<strlen(str);i++){
        count[str[i]-'a']++;
    }

    while (*str!='\0')
    {
        if(count[*str-'a']>0)
        {
            count[*str-'a']=0;
            *tmp=*str;
            tmp++;
        } 
        str++;
    }
    *tmp='\0';
}


int quest4(int *a,int n,double k){
    int high=n-1,low=0,mid;

    int max=a[n-1];
    
    while (low<high)
    {
        mid=(low+high)/2;
        if(a[mid]==k) return a[mid];
        else if(a[mid]>k){
            if(a[mid]<max) max=a[mid];
            high=mid;
        }
        else low=mid+1;
    }
    return max;
    

}



