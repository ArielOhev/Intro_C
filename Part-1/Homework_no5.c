#include <stdio.h>
#include <math.h>


int GCD(int a,int b);

int square(int num);
int cube(int num);
int power(int num,int pwr);

int isEven(int num);
int isOdd(int num);
long Digits(int digit);

int myToLower(char ch);
int myToUpper(char ch);

int charToNum(char,char,char);

int sumOfdevides(int num1,int num2);

int countDvides(int num);

int lowestDvide(int num);

int biggestdvide(int num);

void validfraction(int nume,int deno);

int countnum(int num);

void reversenum(int num);

int main(){
    //1
    // int num=4;
    // printf("The Number is: %d\n",num);
    // printf("square is: %d\n",square(num));
    // printf("Cube is: %d\n",cube(num));
    // printf("Cube is: %d\n",power(num,4));

    // //2
    // printf("%d\n",isEven(num));
    // printf("%d\n",isOdd(num));

    // //3
    // printf("%ld\n",Digits(6));

    // //4
    // char ch = 'a';
    // printf("%d\n",ch);
    // printf("%c %d\n",myToLower(ch),myToLower(ch));
    // printf("%c %d\n",myToUpper(ch),myToUpper(ch));

    // //5
    // char a ='5';
    // char b ='6';
    // char c ='2';
    // printf("%d\n",charToNum(a,b,c));

    // //6
    // int num1=21;
    // int num2 = 10;
    // printf("%d\n",sumOfdevides(num1,num2));

    // //7
    // printf("%d\n",countDvides(25));

    // //8
    // printf("%d\n",lowestDvide(22));

    // //9
    // printf("%d\n",biggestdvide(23));

    // //10
    // validfraction(0,21);

    // //11
    
    //Lab-----------------------
    //1
    printf("%d\n",countnum(538));


    //2
    
    reversenum(5614);


    
    return 0;
}

void reversenum(int num){
    while (num!=0){
        if(num%10!=0){
            printf("%d ",num%10);
            num/=10;
        }
        else{
            num/=10;
        }
    }
}


int countnum(int num){
    int count=0;
    while(num!=0){
        count++;
        num/=10;
    }
    return count;

}



int GCD(int a,int b){
    int temp;
    while (b != 0) {
        temp = a % b;
        
        a = b;
        
        b = temp;
    }
    
    return a;
}

int square (int num){
    return num*num;
}
int cube (int num){
    return num*num*num;
}
int power (int num,int pwr){
    int copy_num=num;
    for (int i=1;i<pwr;i++){
        num=num*copy_num;
    }
    return num;
}

int isEven(int num){
    return (num%2==0 ? 1 :0);
}
int isOdd(int num){
    return (num%2==0 ? 0 :1);
}

long Digits(int digit){
    long digits=1;
    for (int i=1;i<digit;i++){
        digits+=power(10,i);
    }

    return digits;
}

int myToLower(char ch){
    return ((ch >= 65 && ch <= 90) ? ch+32 :-1);
}

int myToUpper(char ch){
    return ((ch >= 97 && ch <= 122) ? ch-32 :-1);
}

int charToNum(char a,char b,char c){
    return(((a>='1'&&a<='9')&&(b>='1'&&b<='9')&&(c>='1'&&c<='9')) ?((100*(a-48))+(10*(b-48))+(c-48)):0);
}

int sumOfdevides(int num1,int num2){
    int sum=1;
    for (int i=2;i<=num2;i++){
        if ((num1%i==0)&&(num2%i==0))
        {
            sum+=i;
        }
    }
    return sum;
}

int countDvides(int num){
    int count=0;

    for (int i=1;i<=num;i++){
        if(num%i==0){
            
            count+=i;
        }
    }

    return (count%2==0 ? 0 :1);
}

int lowestDvide(int num){
    int i=2;
    while(i<=num)
    {
        if(num%i==0){
            return i;
        }
        i++;
    }

    return num;
}

int biggestdvide(int num){
    int temp=num-1;
    while(temp!=0){
        if(num%temp==0){
            return temp;
        }
        temp--;
    }
    return 1;
}

void validfraction(int nume,int deno){
    if(deno==0){
        printf("Can't divide by zero\n");
    }
    else{
        printf("%d/%d = %d/%d",nume,deno,(nume/GCD(deno,nume)),(deno/GCD(deno,nume)));
    }

    
}




