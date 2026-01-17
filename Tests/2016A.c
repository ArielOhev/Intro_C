#include <stdio.h>

int quest2(int n);
int quest4(int *arr,int d,int n);

int main(){
    int n=5;
    printf("%d\n",quest2(n));
    return 0;
}


int quest2(int n){
    int sum=0,num;
    printf("Enter Num\n");
    scanf("%d",&sum);
    int count=0;

    for(int i=0;i<n-1;i++){
        printf("Enter Num\n");
        scanf("%d",&num);
        if(num==sum) count++;
        sum+=num;
    }

    return count;
}
int quest3(char *s,char *s1,char *s2){
    int i=0,j=0;
    int tmp[256]={0};
    while(s1[i]!='\0'){
        tmp[s1[i++]]++;
    }
    i=0;
    while (s2[i]!='\0')
    {
        tmp[s2[i++]]++;
    }
    i=0;
    while (s[i]!='\0')
    {
        tmp[s[i++]]--;
    }
    

    for(int i=0;i<256;i++){
        if(tmp[i]!=0) return 0;
    }

    return 1;
}
int quest4(int *arr,int d,int n){
    int high=n-1;
    int low=0;
    int mid,currNum;


    while (low<high)
    {
        mid=(high+low)/2;
        currNum=arr[mid+1]-arr[mid];
        if(currNum==d) return mid;
        if(currNum>d) high=mid;
        else low=mid+1;
    }

    return -1;
    
}
double quest5(double x, int n){
    double sum_up=x;
    double sum_lower = 1;
    double sum=sum_up/sum_lower;
    double factorial = 1;

    double doule_X=x*x;

    for(int i=1;i<=n;i++){
        sum_up*=doule_X;
        factorial*=i;
        sum_lower=((i*2)+1)*factorial;
        sum+=sum_up/sum_lower;
    }
    return sum;

}























































