#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define R 3
#define C 3
#define N 4


void Printmatrix(int arr[N][N]);
void printArr(int *arr,int n);
double *quest1(int mat[R][C]);
void quest2(int mat[N][N],int *arr);
int quest3(int mat[N][N]);
int main(){
    int mat[N][N]={{1,3,4,9},{2,5,5,2},{3,1,4,1},{8,4,5,1}};
    Printmatrix(mat);
    printf("%d\n",quest3(mat));
    return 0;
}

void Printmatrix(int arr[N][N]){
    for(int i=0;i<R;i++){
        for (int k= 0; k < C; k++)
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
