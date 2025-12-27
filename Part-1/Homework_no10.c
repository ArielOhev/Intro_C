#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

typedef char*verylong;


int quest1(char str[],char str2[]);
int quest2( char str[],char str2[]);
void quest3(char str[]);
void quest4(char str[]);
int quest5(char str[]);
char* quest6(char str[],int *len);
int quest7(char s1[],char s2[]);
char* quest8(char s[],int index,int len);
int count_num(int num);
verylong add_verylong(verylong v1,verylong v2);
void quest10(char *S,char toRemove[]);
int main(){
    char S[]="Abbcbab";
    char toRemove[]="badz";
    quest10(S,toRemove);
    puts(S);
    return 0;
}
int quest1(char str[],char str2[]){
    int *arr=(int*)calloc(256,sizeof(int));
    for(int i=0;i<strlen(str);i++){
        arr[str[i]]++;
    }
    for(int j=0;j<strlen(str2);j++){
        if(arr[str2[j]]==0){
            return 0;
        }
        arr[str2[j]]--;
    }   
    free(arr);
    return 1;
}
int quest2( char str[],char str2[]){
    if(strlen(str)!=strlen(str2)){
        return 0;
    }
    int count[256]={0};
    for(int i=0;i<strlen(str);i++){
        count[str[i]]++;
    }
    for(int j=0;j<strlen(str2);j++){
        if(count[str2[j]]==0){
            return 0;
        }
        count[str2[j]]--;
    }
    return 1;
}
void quest3(char str[]){
    char *ptr=str;
    char *temp=str;

    while(*ptr!='\0'){
        *temp=*ptr;
        if(*ptr==*(ptr+1)){
            while(*ptr==*(ptr+1)){
                ptr++;
            }
        }
        ptr++;
        temp++;
    }
    *temp='\0';
}
void quest4(char str[]){
    char *ptr=str;
    char *temp=str;
    int count=49;

    while(*ptr!='\0'){
        *temp=*ptr;
        if(*ptr==*(ptr+1)){
            while(*ptr==*(ptr+1)){
                ptr++;
                count++;
            }
            temp++;
            *temp=count;
            count=49;
        }
        ptr++;
        temp++;
    }
    *temp='\0';
}
int quest5(char str[]){
    int len = strlen(str);
    int arr[256];
    int odd_count=0;

    for(int i=0;i<len;i++){
        arr[str[i]]++;
    }

    for(int i=0;i<len;i++){
        if(arr[str[i]]%2!=0){
            odd_count++;
        }
    }

    if(odd_count>1){
        return 0;
    }

    return 1;
}
char* quest6(char str[],int *len){
    char *s=(char*)malloc(*len*sizeof(char));
    char *ptr=s;
    int arr[256]={0};

    for(int i=0;i<*len;i++){
        arr[str[i]]++;
    }
    for(int i=0;i<*len;i++){
        if(arr[str[i]]%2!=0){
            *ptr=str[i];
            ptr++;
            arr[str[i]]=0;            
        }
    }
    *ptr='\0';
    char *temp =s+1;
    *len=strlen(temp);
    return temp;
}
int quest7(char s1[],char s2[]){
    int len=strlen(s1);
    if(strlen(s2)!=len){
        return 0;
    }
    int sum;
    for(int i=0;i<len;i++){
        sum = abs(s1[i]-s2[i]);
        if(sum!=0 && sum!=32){
            return 0;
        }
    }
    return 1;
}
char* quest8(char s[],int index,int len){
    char *str=(char*)malloc(len*sizeof(char));
    char *ptr=str;
    for(int i=index;i<(len+index);i++){
        if(s[i]=='\0' || s[i]==' '){
            free(str);
            return NULL;
        }
        *ptr=s[i];
        ptr++;
    }

    *ptr='\0';
    return str;

}
int count_num(int num){
    int count=0;
    while (num>0)
    {
        num/=10;
        count++;
    }
    return count;
}
int strtoNum(char str[]){
    int num = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - '0');
    }
    return num;
}
verylong add_verylong(verylong v1,verylong v2){
    int num_v1=strtoNum(v1);
    int num_v2=strtoNum(v2);

    int num_v3=num_v1+num_v2;
    int len_v=count_num(num_v3);
    verylong v=(verylong)malloc((len_v+1)*sizeof(verylong));
    verylong ptr=v;

    for(int i=len_v-1;i>=0;i--){
        v[i]=(num_v3%10)+'0';
        num_v3/=10;
    }
    v[len_v]='\0';

    return v;
}

void quest10(char *S,char toRemove[]){
    int arr[256]={0};
    int len_S=strlen(S);
    int len_toRemove=strlen(toRemove);
    for(int i=0;i<len_toRemove;i++){
        arr[toRemove[i]]++;
    }
    char *read=S;
    char *write=S;
    for(int j=0;j<len_S;j++){
        if(arr[S[j]]==0){
            *write=*read;
            write++;
        }
        read++;
    }
    *write='\0';
}

