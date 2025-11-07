#include <stdio.h>

int main(){
    //1
    printf("hello Ariel\n");
    //2
    double pi = 3.141592;
    printf("%.2lf",pi);
    //3
    printf("\n  *\n ***\n*****\n");
    //4
    int a=5,b=3;
    printf("%d\n",(a*b));
    printf("%d\n",(a/b));
    printf("%d\n",(a%b));
    //5
    (a ^= b, b ^= a, a ^= b);       // swap in one row using XOR (works only for integers and a!=b)
    printf("after swapping a=%d b=%d\n",a,b);

    return 0;
}