#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define R 3
#define C 5



int main(){
    return 0;
}

int sum_increasing_minus_decreasing(int *a,int n){
    int index=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]) index=i;
    }

    int sum_increasing=0;
    int sum_decreasing=0;

    for(int i=0;i<n;i++){
        if(i<index) sum_increasing+=a[i];
        else sum_decreasing+=a[i];
    }
    return sum_increasing-sum_decreasing;
}

int sum_increasing_minus_decreasing(int *a,int n){
    int first = a[n-1];
    int second = a[n-2];

    if(n==2){
        
        return first+second;

    }
    int third=a[n-3];
    if(third>first && second>third) return sum_increasing_minus_decreasing(a,n-2) - (second+first);

    return first>second ? sum_increasing_minus_decreasing(a,n-1) + first : sum_increasing_minus_decreasing(a,n-1) - first;

}


int numLength(int num){
    int count=0;
    while (num>0)
    {
        count++;
        num/=10;
    }
    return count;
}

int quest3(char *str){
    if(strlen(str)<4) return 0;
    int i=0;
    int firstNum= strToNum(str,(i++),1);
    int secondNum = strToNum(str,(i++),1);
    int sum=firstNum+secondNum;
    int currNum;

    while (str[i+1]!='\0')
    {
        for(int j=i;j<numLength(sum)+i;j++){
            if(str[j]=='\0') return 0;
        }

        currNum=strToNum(str,i,numLength(sum));
        if(currNum!=sum) return 0;
        sum=currNum+secondNum;
        secondNum=currNum;
        i+=numLength(currNum);
    }
    return 1;
    
}



