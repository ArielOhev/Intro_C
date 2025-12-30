#include <stdio.h>
void sod(int n);
int main(){
    sod(5);    
    return 0;
}

void sod(int n){
    printf("1\n");
    printf("%d\n",n);
    n-=2;
    if(n>0){
        sod(n+1);
    }
}
