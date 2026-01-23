#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define R 3
#define N 4



int main(){
    return 0;
}

int checkWord(char *word){
    int count[26]={0};
    
    for(int i=0;i<strlen(word);i++){
        count[word[i]-'a']++;
    }

    for(int i=0;i<strlen(word);i++){
        if(count[word[i]-'a']>1) return 0;
    }
    return 1;
}

int checkLang(char* sentence){
    int index=0;
    char *tmp;
    int flag=1;
    

    for(int i=0;i<=strlen(sentence);i++){
        if(flag==0 &&(sentence[i]>='a' && sentence[i]<= 'z')){
            index=i;
            flag=1;
        }

        if(sentence[i]<'a' && sentence[i]> 'z'){
            tmp=(char*)malloc((i-index+1)*sizeof(char));
            assert(tmp);
            while (index<i)
            {
                tmp[index]=sentence[index];
                index++;
            }
            if(checkWord(tmp)==0) return 0;
            free(tmp);
            flag=1;
        }
    }
    return 1;
}

int MaxRelative(int *arr,int n){
    if(n==3){
        return (arr[1]-arr[0])+(arr[1]-arr[2]);  
    }

    int max= MaxRelative(arr+1,n-1);
    int currNum= (arr[1]-arr[0])+(arr[1]-arr[2]);
    if (max>currNum) return max;
    else return currNum;
}

void sort_arr(int *a,int n){
    int start=0;
    int end=n-1;
    int tmp;
    
    for(int i=0;i<n;i++){
        if(a[i]==0){
            tmp=a[i];
            a[i]=a[start];
            a[start]=tmp;
            start++;
        }
        else if(a[i]==2){
            tmp=a[i];
            a[i]=a[end];
            a[end]=tmp;
            end--;
        } 
    }
}

void sort_Mat(int mat[N][N]){
    int count[N*N]={0};
    int index=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            count[index]=mat[i][j];
            index++;
        }
    }

    merge_sort(count,0,N*N);
    index=0;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mat[i][j]=count[index];
            index++;
        }
    }
}






