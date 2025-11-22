#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main()
{
    //1
    // int num,i;
    // int n=0;
    
    // printf("Enter Number\n");
    // scanf("%d",&num);
    
    // for (i=1;i<=num;i++)
    // {
    //     if (i%3==0)
    //     {
    //         printf("Fizz\n");
    //     }
    //     else if(i%5==0)
    //     {
    //         printf("Buzz\n");
    //     }
    //     else if(i%15==0){
    //         printf("FizzBuzz\n");
    //     }
        
    //     else{
    //         printf("%d\n",i);
    //     }
        
    // }
    
    
    
    //2
    
    // int x,i;
    
    // printf("Enter Number\n");
    // scanf("%d",&x);
    
    // printf("%d\n",(40-((1000-x)/25)));
    
    // for(i=x;i<x+25;i++){
    //     printf("%d\n",i);
    // }
    
    
    //3
    
    // int x,i;
    
    // printf("Enter Number\n");
    // scanf("%d",&x);
    
    // for (i=20;i>0;i=i/2){
    //     printf("%d %dNIS\n",(x/i),i);
    //     x=x%i;
    // }
    
    //5
    
    // int x,i,sum1=1,sum2=0;
    
    // printf("Enter Number\n");
    // scanf("%d",&x);
    
    // for (i=1;i<=x;i++){
    //     sum1*=i;
    //     sum2+=i;
        
    // }
    
    // printf("%lf\n",((double)sum1/sum2));
    
    
    
    //6
    
    // int x,i=0,max=0,min;
    
    // printf("Enter Number\n");
    // scanf("%d",&x);
    
    // if(x==-1){
    //     printf("no min no max ,numbers 0\n");
    // }
    // else{
    //     min=x;
    
    // while(x!=-1){
        
    //     i++;
    //     if(x>max){
    //         max=x;
    //     }
    //     if(x<min){
    //         min=x;
    //     }
    //     printf("Enter Number\n");
    //     scanf("%d",&x);
        
    // }
    
    // printf("%d numbers, max=%d,min=%d\n",i,max,min);
    // }
    
    
    //7
    
    // int x,reminder;
    
    // printf("Enter Number\n");
    // scanf("%d",&x);
    
    // while(x!=0){

    //     reminder=x%2;
    //     if(reminder==1){
    //         printf("1, ");
    //     }
    //     else{
    //         printf("0, ");
    //     }
    //     x=x/2;
    // }

    //8

    // double an,a1,q,S,i;
    // int n;

    // printf("Enter a1\n");
    // scanf("%lf",&a1);
    // printf("Enter n\n");
    // scanf("%d",&n);
    // printf("Enter q\n");
    // scanf("%lf",&q);

    // for (i=1;i<=n;i++){
    //     an=a1;
    //     a1=a1*q;
    //     S+=an;
    // }
    // printf("A%d= %.1lf\n",n,an);
    // printf("S%d= %.1lf\n",n,S);

    //9

    // int n;
    // double sum=1;
    // printf("Enter Number\n");
    // scanf("%d",&n);

    // if(n%2==0){
    //     printf("Even Number\n");
    // }
    // else{
    //     for (double i=2;i<n;i+=2){
    //         sum+=i/(i+1);
    //     }
    //     printf("Sum= %.2lf\n",sum);
        
    // }


    //10

    // int max=0,pos_max=0,min=10,pos_min=0,digit,pos=0;
    // long num=0;
    // printf("Enter Number\n");
    // scanf("%ld",&num);

    // while(num>0){
    //     pos++;
    //     digit=num%10;
    //     if(digit>=max){
    //         max=digit;
    //         pos_max=pos;
    //     }
    //     if(digit<=min){
    //         min=digit;
    //         pos_min=pos;
    //     }
    //     num=num/10;
    // }
    // printf("Max Digit= %d, Position= %d\n",max,pos_max);
    // printf("Min Digit= %d, Position= %d\n",min,pos_min);

    //12

    // long n;
    // int digit;
    // double sum1=1,sum2=1;
    // printf("Enter Number\n");
    // scanf("%ld",&n);

    // while(n>0){
    //     digit=n%10;
    //     if (digit%2==0){
    //         sum1*=digit;
    //     }
    //     else{
    //         sum2*=digit;
    //     }
    //     n=n/10;
    // }
    // printf("Product of Even Digits= %.1lf\n",sum1);
    // printf("Product of Odd Digits= %.1lf\n",sum2);

    // printf("Sum of Even Digits divided by Odd Digits= %.2lf\n",sum1/sum2);

    //13

    srand(time(0));
    int guess,number,tries=0;
    int random_num = rand() % 10 + 1; // Random number between 1 and 10
    printf("%d\n",random_num); // For testing purposes
    printf("Guess the number between 1 and 10:\n");
    scanf("%d",&guess);

    if (random_num==guess){
        tries=1;
    }
    else{
        while(guess!=random_num){
            tries++;
            printf("Wrong guess. Try again:\n");
            scanf("%d",&guess);
        }
    }

    switch (tries)
    {
    case 1:
        printf("I believe you have cheated...\n");
        break;
    case 2:
        printf("Excellent guess!\n");
        break;
    case 3:
        printf("Excellent guess!\n");
        break;
    case 4:
        printf("You played well\n");
        break;
    case 5:
        printf("You played well\n");
        break;
    case 6:
        printf("Average game\n");
        break;
    case 7:
        printf("Average game\n");
        break;
    case 8:
        printf("Poor game\n");
        break;
    case 9:
        printf("Poor game\n");
        break;
    case 10:
        printf("Poor game\n");
        break;
    }

    if (tries>10){
        printf("Seriously? There are only ten choices...\n");
    }
    














    return 0;
}
    