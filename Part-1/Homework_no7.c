#include <stdio.h>

void sortThreePointers(int *num1Ptr, int *num2Ptr, int *num3Ptr);
void quest2(int *num,int *digit);
int quest3(int *n,int*x,int*c);
void quest4(int *ar,int n);
int quest5(int *ar,int *n,int*key);
void maxmax(int *a, int n, int *max_even, int *even, int *max_odd, int *odd);
int iterativePolindrom(int *arr,int n);
int recoursivePolindrom(int *arr,int n);
int printArr(int *arr,int n);
int revPrintArr(int *arr,int n);
int quest11(int *arr,int n);
int recquest11(int *arr,int n);
int main(){
    int n=6;

    int arr[6]={1,2,5,9,20,40};
    printf("%d\n",recquest11(arr,n));
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//1
void sortThreePointers(int *num1Ptr, int *num2Ptr, int *num3Ptr) {
    int a = *num1Ptr;
    int b = *num2Ptr;
    int c = *num3Ptr;

    // 1. חישוב המקסימום באמצעות אופרטור טרינרי מקונן
    // התרגום: האם a גדול מ-b? 
    // אם כן: בדוק אם a גדול מ-c (אם כן a הכי גדול, אחרת c)
    // אם לא: בדוק אם b גדול מ-c (אם כן b הכי גדול, אחרת c)
    int max = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);

    // 2. חישוב המינימום באותה שיטה בדיוק (רק עם סימן הפוך)
    int min = (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);

    // 3. חישוב המספר האמצעי (טריק מתמטי: סכום כולם פחות המקסימום והמינימום)
    int mid = (a + b + c) - max - min;

    // 4. השמת הערכים חזרה למצביעים לפי הסדר המבוקש
    *num1Ptr = max; // הראשון מקבל את המקסימום
    *num2Ptr = mid; // השני מקבל את האמצעי
    *num3Ptr = min; // השלישי מקבל את המינימום
}

//2

void quest2(int *num,int *digit){
    int count=0;
    int sum=0;
    if(*num==0){
        count++;
    }

    while(*num>0){
        if((*num%10)<*digit){
            sum+=*num%10;
            count++;
        }

        *num/=10;
    }

    printf("%d %d\n",sum,count);
}

//3
int quest3(int *n,int*x,int*c){
    int sum=0;
    (*c) *= (*n)--;
    for(int i=(*n); i>0;i--){
        sum+=(*c) * (*n);
    }

    return sum;
}

//4
void quest4(int *ar,int n){
    int maxi=0;

    for (int i=0;i<n-1;i++){
        if(ar[i]+ar[i+1]>ar[maxi]+ar[maxi+1]){
            maxi=i;
        }
    }
    printf("%d + %d = %d\n",ar[maxi],ar[maxi+1],ar[maxi]+ar[maxi+1]);

}

int LowestNum(int *arr,int n){
    int low1=0;
    for(int i=1;i<n-1;i++){
        if(arr[i]<arr[low1]){
            low1=i;
        }
    }

    return low1;
}
//5
int quest5(int *ar,int *n,int *key){
    int lowIndex=LowestNum(ar,(*n));
    
    for(int i=0;i<(*n)-1;i++){
        if(i!=lowIndex &&(ar[i]+ar[lowIndex]<(*key))){
            *n=ar[i];
            *key=ar[lowIndex];
            printf("%d %d\n",*n,*key);
            return 1;
        }
    }
    *n=-1;
    *key=-1;
    printf("%d %d\n",*n,*key);
    return 0;
}

//6
void maxmax(int *a, int n, int *max_even, int *even, int *max_odd, int *odd){
    for(int i=0;i<n-1;i++){
        if(a[i]%2==0 && a[i]>*max_even){
            *even=1;
            *max_even=a[i];
        }
        if(a[i]%2!=0 && a[i]>*max_odd){
            *odd=1;
            *max_odd=a[i];
        }
    }
}

//7 a
int iterativePolindrom(int *arr,int n){
    n--;
    for(int i=0;i<n-1;i++){
        printf("%d %d\n",arr[i],arr[n]);
        if(arr[i]!=arr[n]){
            return 0;
        }
        n--;
    }
    return 1;
}

//7 b
int recoursivePolindrom(int *arr,int n){
    if(n<=1){
        return 1;
    }
    if(*arr!=arr[n-1]){
        return 0;
    }
    return recoursivePolindrom(arr+1,n-2);
} 


//8 a
int printArr(int *arr,int n){
    if(n==0){
        return 0;
    }
    printf("%d\n",*arr);
    printArr(arr+1,n-1);
}

//8b
int revPrintArr(int *arr,int n){
    if (n==0){
        return 0;
    }
    printf("%d\n",arr[n-1]);
    revPrintArr(arr,n-1);
}

//9
double avgArr(int *arr,int n){
    if(n==1){
        return 1;
    }
    return avgArr(arr+1,n-1)+(*arr/5);

}

//11a
int quest11(int *arr,int n){
    int sum=*arr;
    for(int i=1;i<n-1;i++){
        if(arr[i]<sum){
            return 0;
        }
        sum+=arr[i];
    }
    return 1;
}

//11b
int recquest11(int *arr,int n){
    if(n<=1){
        return 1;
    }
    
    if(arr[1]<arr[0]){
        return 0;
    }
    arr[1]=arr[0]+arr[1];
    return recquest11(arr+1,n-1);
}

