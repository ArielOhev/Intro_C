#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void printArr(int *arr,int n);
int *quest1(int n);
int *quest2(int *arr,int n,int *isEven);
int *quest3(int *arr1,int *arr2);
void *quest4(int *arr1,int n);
int *quest5(int *arr1,int *n);
int quest6(int *arr,int n);

int main(){

    int arr[5]={1,3,3,2,3};
    int n=5;

    printf("%d\n",quest6(arr,n));
    // free(arr2);
    return 0;
}
void printArr(int *arr,int n){
    printf("arr ={ ");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf(" }\n");

}

int *quest1(int n){
    int *arr=(int*)malloc(n*sizeof(int));
    arr[0]=2;
    arr[1]=1;
    assert(arr);
    
    for(int i=2;i<=n;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    
    return arr;
}

int *quest2(int *arr,int n,int *isEven){
    int *arr2 = NULL; // 1. אתחול ל-NULL חובה!
    int count = 0;    // מתחילים מ-0 איברים שנמצאו

    // בדיקה מה אנחנו מחפשים (זוגי או אי-זוגי)
    // אני מניח ש-*isEven מכיל 1 אם רוצים זוגי, אחרת אי-זוגי
    int targetRemainder = (*isEven) ? 0 : 1; 

    for (int i = 0; i < n; i++) {
        // בדיקה מאוחדת לזוגי/אי-זוגי
        if (abs(arr[i] % 2) == targetRemainder) {
            
            count++; // מצאנו איבר חדש

            // 2. realloc על arr2 (המערך החדש), לא על arr!
            int *temp = realloc(arr2, count * sizeof(int));
            assert(temp); // מוודאים שההקצאה הצליחה
            arr2 = temp;

            // 3. שמירה במקום הנכון (בסוף המערך)
            arr2[count - 1] = arr[i];
        }
    }

    *isEven = count; // החזרת הגודל החדש דרך הפוינטר
    return arr2;
}

int *quest3(int *arr1,int *arr2){
    int *arr=(int*)malloc(3*sizeof(int));
    assert(arr);
    arr[0]=(arr1[1]*arr2[2])-(arr1[2]*arr2[1]);
    arr[1]=(arr1[2]*arr2[0])-(arr1[0]*arr2[2]);
    arr[2]=(arr1[0]*arr2[1])-(arr1[1]*arr2[0]);
    return arr;
}

int sumOfArray(int *arr,int n){
    int sum=1;
    for(int i=0;i<n;i++){
        sum*=arr[i];
    }
    return sum;
}

void *quest4(int *arr1,int n){
    int sum=sumOfArray(arr1,n);
    for(int i=0;i<n;i++){
        arr1[i]=(sum/arr1[i]);
    }
}

int *quest5(int *arr1,int *n){
    int *arr=calloc(*n+1,sizeof(int));
    assert(arr);
    int count=0;
    for(int i=0;i<*n;i++){
        arr[arr1[i]]++;
    }
    int *arr2=NULL;
    for(int i=0;i<=*n;i++){
        if(arr[i]==0){
            count++;
            int *temp=realloc(arr2,count*sizeof(int));
            assert(temp);
            arr2=temp;

            arr2[count-1]=i;
        }
    }
    free(arr);
    *n=count;
    return arr2;
}

int quest6(int *arr,int n){
    int *a=(int*)calloc(n+1,sizeof(int));
    assert(a);
    for(int i=0;i<n;i++){
        a[arr[i]]++;
    }
    for(int i=0;i<=n;i++){
        if(a[i]>(n/2)){
            free(a);
            return i;
        }
    }
    free(a);
    return -1;
}