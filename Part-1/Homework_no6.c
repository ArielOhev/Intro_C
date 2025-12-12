#include <stdio.h>
#include <math.h>



//4
double quest4(int n){
    if (n==0 || n==1 || n==2 ){
        return 1;
    }

    else if(n>2 && n%2==0){
        return (quest4(n-1)+quest4(n-2)+quest4(n-3));
    }

    else{
        return(quest4(n-1)-quest4(n-3));
    }
}

//5
int MaxNumber(int n){
    int curr;
    int max;
    if (n==0){
        return -1;
    }

    printf("Enter number\n");
    scanf("%d",&curr);

    max=MaxNumber(n-1);

    if(curr>max){
        return curr;
    }
    return max;
    
}


//6
int LowestNum(int n){
    int curr;
    int min;

    if(n==0){
        return __INT_MAX__;
    }
    printf("Enter Number\n");
    scanf("%d",&curr);

    min=LowestNum(n-1);

    if(curr<min){
        return curr;
    }
    return min;
}

//7

void Printbin(int num){
    int n=num%2;
    if(num==0){
        return;
    }
    Printbin(num/2);

    printf("%d",n);
    
}

//8 - check!!!!!!
void quest8(int num,char ch1,char ch2){

    if (num==0){
        return ;
    }
    quest8(num-1,ch1,ch2);
    printf("%c ",ch1);
    printf("%c %c",ch2,ch2);
    
}

//9
int switch_a(int num){
    int n=num%10;
    int count=1;
    if(num=0){
        return -1;
    }

    return(num/10);
}

//10
int evenSum(int num){
    int sum=0;
    if (num==0){
        return 0;
    }

    sum+=num%10;
    return(evenSum(num/10));
    if(sum%2==0){
        return 1;
    }
    else{
        return 0;
    }

}

int binToDec(int num){
    if(num==0){
        return 1;
    }
    if (num%2!=0){
        return binToDec(num/10)+(num%10)*2;
    }
    else{
        return binToDec(num/10);
    }
}

int decToBin(int num){
    if (num==0){
        return 0;
    }

    if(num%2!=0){
        return 10*decToBin(num/2)+1;
    }
    else{
        return 10*decToBin(num/2);
    }
}


int rec(int a,int b){
    if(a<=b ){
        return a;
    }

    if(a>b){
        printf("%d\n",a-b);
        return rec(a-b,b);
    }
    else{
        return rec(a,b-a);
    }


}


int main(){
    printf("%d\n",rec(11,3));
    return 0;
}