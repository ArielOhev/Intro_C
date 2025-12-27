#include <stdio.h>
#include <math.h>


void quest1(int n);
int sumofdviders(int n);
void quest2(int n);
int number_of_bin_ones(int num);
int diff(int num);
int bigger_rev(int n);

int main(){
    int n=7;
    bigger_rev(n);
    return 0;
}
//1 - Code Review
// Correctness: The code is logically correct and meets all the requirements of the question.
// Libraries: Using the abs() function requires including the <stdlib.h> library at the beginning of the file.
// Variable Naming:
// The variable reminder should be spelled remainder.
// The variable count does not act as a counter; instead, it stores a difference. A more appropriate name would be min_diff.
void quest1(int n){
    int count=n;
    int x=0,y=0,reminder;
    for(int i=0;i*3<=n;i++){
        reminder=n-3*i;
        if(reminder%5==0){
            if(abs(i-(reminder/5))<count){
                x=i;
                y=reminder/5;
                count=abs(i-reminder/5);
            }
        }
    }
    printf("(%d,%d)\n",x,y);
}

//2 - Code Review
// Key Fixes:
// Speed: Loop runs up to n/2.
// Logic: i < friendVal prevents printing (220,284) and then (284,220).
// Naming: divisors instead of dviders.
int sumofdviders(int n){
    int sum=0;
    for(int i=1;i<n;i++){
        if(n%i==0){
            sum+=i;
        }
    }
    return sum;
}
void quest2(int n){
    int sum;
    for(int i=n-1;i>0;i--){
        sum=sumofdviders(i);
        if(sumofdviders(sum)==i && sum!=i){
            printf("(%d,%d)\n",i,sum);
        }
    }
}

//3 - Code Review
// You nailed it. The logic is flawless. The refactored version above is just a "pro tip" for cleaner code, but your version is 100% acceptable for an exam.
int number_of_bin_ones(int num){
    if(num==0){
        return 0;
    }
    if(num%2!=0){
        return number_of_bin_ones (num/2) +1 ;
    }
    return number_of_bin_ones(num/2);
}

//4 - Code Review
//Your code is logically correct, concise, and elegant. You perfectly implemented the requirement to calculate "(Sum of Even Digits) - (Sum of Odd Digits)".
int diff(int num){
    if (num==0){
        return 0;
    }
    int n=num%10;
    return diff(num/10)+ (n%2==0 ? n : -n); 
}

//5 Code Review
//This is a high-quality implementation of the requested problem. You have successfully mastered the "post-recursion" logic (the actions that happen during the unwinding of the stack).
int bigger_rev(int n){
    int num;
    printf("Enter number (0 to stop): ");
    scanf("%d", &num);

    if (num==0){
        return 0;
    }
    int max = bigger_rev(n);
    if(num>max){
        printf("%d\n",num);
    }
    return (num>max ? num : max);
}



