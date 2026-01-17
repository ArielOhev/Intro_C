#include <stdio.h>

int quest3(int num);
int main(){
    int num=36;
    printf("%d\n",quest3(num));

    return 0;
}

int quest3(int num){
    for(int i=0;i<=num;i++){
        if((i*i)==num) return 1;
    }
    return 0;
}


