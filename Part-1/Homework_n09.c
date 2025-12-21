#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define R 4
#define C 3
#define N 3


void Printmatrix(int arr[N][N]);
void printArr(int *arr,int n);
double *quest1(int mat[R][C]);
void quest2(int mat[N][N],int *arr);
int quest3(int mat[N][N]);
int quest4(int mat[N][N]);
int quest5(int mat[N][N]);
void quest6(int mat[N][N],int *r,int *c,int key);
int quest7(int mat[N][N]);
void quest8(int mat[R][C],int *r,int *c,int key);
int quest9(int mat[N][N]);
void quest10(int mat[N][N]);
int main(){
    int mat[N][N]={{-7,0,1},{5,5,12},{18,26,36}};
    quest10(mat);
    Printmatrix(mat);
    return 0;
}

void Printmatrix(int arr[N][N]){
    for(int i=0;i<N;i++){
        for (int k= 0; k < N; k++)
        {
            printf("%d ",arr[i][k]);
        }
        printf("\n");
    }
}
void printArr(int *arr,int n){
    printf("arr ={ ");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf(" }\n");

}
double *quest1(int mat[R][C]){
    double *arr=(double*)calloc(R,sizeof(double));
    assert(arr);
    for(int i=0;i<R;i++){
        for(int k=0;k<C;k++){
            arr[i]+=mat[i][k];
        }
        arr[i]/=(double)C;
    }
    return arr;
}
void quest2(int mat[N][N],int *arr){
    for(int i=0;i<N;i++){
        for(int k=0;k<N;k++){
            printf("%d\n",mat[i][k]-mat[k][i]);
            arr[i]+=(mat[i][k]-mat[k][i]);
        }
    }
}
int quest3(int mat[N][N]){
    int sum =0;
    for(int i=0;i<N;i++){
        sum+=(mat[i][i]*mat[i][N-1-i]);
    }
    return sum;
}
int quest4(int mat[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(mat[i][j]!=mat[j][i]){
                return 0;
            }
        }
    }
    return 1;
}
int quest5(int mat[N][N]){
    for(int i=0;i<N;i++){

        if(mat[i][i]>mat[i+1][i+1] || mat[i][i]>mat[N-i-1][i] || mat[i+1][N-1-(i+1)]<mat[i][N-1]){
            return 0;
        } 
    }
    return 1;
}
void quest6(int mat[N][N],int *r,int *c,int key){
    if(*r>=N){
        *r=-1;
        *c=-1;
        return ;
    }
    // printf("%d\n",mat[*r][*c]);
    if(mat[*r][*c]==key){
        // printf("%d hh\n",mat[*r][*c]);
        return;
    }

    if(*c<N-1){
        *c+=1;
        printf("%d\n",*c);
        quest6(mat,r,c,key);
    }
    else{
        *r+=1;
        *c-=(N-1);
        quest6(mat,r,c,key);
    }
}
int quest7(int mat[N][N]){
    int *ptr=&mat[0][0];

    for(int i=0;i<N*N;i++){
        if(*ptr>*(ptr+1)){
            return 0;
        }
        ptr++;
    }
    return 1;
    
}
void quest8(int mat[R][C],int *r,int *c,int key){
    if(*r>=R){
        *r=-1;
        *c=-1;
        return;
    }

    if(mat[*r][*c]==key){
        return;
    }
    if(*c<C){
        *c+=1;
        quest8(mat,r,c,key);
    }
    else{
        *c=0;
        *r+=1;
        quest8(mat,r,c,key);
    }

}
int quest9(int mat[N][N]){
    int *ptr=&mat[0][0];
    int sum=0;
    for(int i=1;i<=N*N;i++){
        sum+=i-(*ptr);
        ptr++;
    }
    int num=(sum>0)? 0: 1;
    return num;
    
}
void quest10(int mat[N][N]){
    int mat2[N][N]={0};

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mat2[i][j]=mat[N-1-i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            mat[i][j]=mat2[i][j];
        }
    }
}

