#include <stdio.h>
#include <math.h>

int main(){
    //1
    // int num,base2=0,base8=0,base4=0,rem,i=1;

    // printf("Enter a decimal number: ");
    // scanf("%d",&num);
    // int temp=num;
    // while(temp!=0){
    //     rem=temp%2;
    //     base2+=rem*i;
    //     temp/=2;
    //     i*=10;
    // }
    // printf("Binary of %d is: %d\n",num,base2);
    // temp=num;
    // i=1;
    // while(temp!=0){
    //     rem=temp%8;
    //     base8+=rem*i;
    //     temp/=8;
    //     i*=10;
    // }
    // printf("Octal of %d is: %d\n",num,base8);
    // temp=num;
    // i=1;
    // while(temp!=0){
    //     rem=temp%4;
    //     base4+=rem*i;
    //     temp/=4;
    //     i*=10;
    // }
    // printf("Quaternary of %d is: %d\n",num,base4);

    //2
    
    int n=8,digit,one_tries=0,two_tries=0;
    long base2_num;

    printf("Enter Number\n");
    scanf("%ld\n",&base2_num);

    while (base2_num>0)
    {
        digit=base2_num%10;
        base2_num=base2_num/10;
        printf("%d\n",digit);
    }
    

    








    return 0;
}