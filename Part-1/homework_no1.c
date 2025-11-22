#include <stdio.h>

int main(){

    int currentYear=2025;
    int age = 23;

    printf("%d\n",(currentYear-age));

    printf("*     *\n *   * \n  * *  \n   *   \n *  * \n*     *\n");
    //3
    long ID =325045193;
    double salary =2;
    int workingHours=8;
    int workingDays=5;
    int firedYear=2025;
    int hireYear=2000;

    int compensation = (salary * workingHours * workingDays)*(firedYear - hireYear);

    printf("ID: %d\n your compensation is:%d",ID,compensation);
    return 0;

    //5
    int speed=50;
    int time=6;
    int distance=speed*time;
    printf("Distance: %d",distance);
}