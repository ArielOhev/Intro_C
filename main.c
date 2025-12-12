#include <stdio.h>

int main(){
    int x = 1, y = 3, z;
    z = x-- + --y;
    printf("x=%d,y=%d,z=%d\n", x,y,z);
    return 0;
}