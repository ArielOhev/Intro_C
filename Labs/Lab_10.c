#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void lettersort(char *str);

int main(){
    char str[]="happynewyear";
    printf("%s\n",str);
    lettersort(str);
    printf("%s\n",str);

    return 0;
}

void lettersort(char *str){
    int *ptr=(int*)calloc(256,sizeof(int));
    assert(ptr);
    char *pStr=str;

    while (*str!='\0')
    {
        ptr[*str]++;
        str++;
    }
    for(int i=0;i<256;i++){
        if(ptr[i]>0){
            while (ptr[i]>0)
            {
                *pStr=i;
                pStr++;
                ptr[i]--;
            }            
        }
    }
    *pStr='\0';
    free(ptr);
}
