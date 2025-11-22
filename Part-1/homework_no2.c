#include <stdio.h>
#include <math.h>

int main(){
    //1
    int number;
    printf("Hellooooooo\n");
    printf("Enter Number:\n");
    scanf("%d",&number);
    printf("Your slant is: %lf\n", sqrt(2*(number*number)));

    //3
    double a1,d,sum,an;
    int n;
    printf("Enter a1\n");
    scanf("%lf",&a1);
    printf("Enter d\n");
    scanf("%lf",&d);
    printf("Enter n\n");
    scanf("%d",&n);

    an =a1 + d*(n-1);
    printf("an is:%.1lf\n",an);

    //4
    sum = n*(a1+an)/2;
    printf("Sum is:%.1lf\n",sum);

    //5
    double q;
    printf("Enter pow:\n");
    scanf("%lf",&q);
    printf("your result is:%.1lf",(a1*pow(q,n-1)));


    return 0;
}