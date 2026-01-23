#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define N 4

int main(){
    return 0;
}

int quest1(int n){
    if(n<10){
        return 9-n;
    }

    int digit=9-(n%10);
    return (quest1(n/10)*10)+digit;
}

int quest2(int num){
    for(int i=num/2;i>0;i--){
        if(i%num==0) return i;
    }
}

char *quest3(char *s1,char *s2){
    int *countChar= (int*)calloc(256,sizeof(int));
    assert(countChar);
    for(int i=0;i<strlen(s1);i++){
        countChar[s1[i]]++;
    }
    int size=0;

    for(int i=0;i<strlen(s2);i++){
        if(countChar[s2[i]]>0){
            size++;
            countChar[i]++;
        }
    }

    char *s=(char*)calloc(size+1,sizeof(char));
    assert(s);
    for(int i=0;i<strlen(s2);i++){
        while (countChar[i]>0)
        {
            *s=s2[i];
            s++;
            countChar[i]--;
        }
    }
    *s='\0';
    free(countChar);
    return s;
}

void swap(int *a,int *b){
    int *tmp=*b;
    *b=*a;
    *a=*tmp;
}

int quest4(int *arr,int n){
    int *writer=arr;
    int *reader =arr;
    int last = arr[n-1];
    int count=0;

    while (*writer!=last)
    {
        if(*reader>*writer){
            count++;
            writer++;
            swap(reader,writer);
        }
        reader++;
    }
    return count;
}

int quest5(int mat[N][N]){
    int higher=1;
    int lower=-1;
    int currNum=mat[0][0];

    for(int i=1;i<N;i++){
        if(higher>0 && mat[i][i]>currNum){
            lower=0;
            currNum=mat[i][i];
        }
        if(lower<0 && mat[i][i]<currNum){
            higher=0;
            currNum=mat[i][i];
        }
        else return 0;
    }

    for(int i=0;i<N;i++){
        if(higher>0 && mat[i][N-(i+1)]>currNum){
            lower=0;
            currNum=mat[i][N-(i+1)];
        }
        if(lower<0 && mat[i][N-(i+1)]<currNum){
            higher=0;
            currNum=mat[i][N-(i+1)];
        }
        else return 0;
    }

    if(higher>0) return higher;
    return lower;
}
















