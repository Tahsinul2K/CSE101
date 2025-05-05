/*Write a C program to enter month number between(1-12) and print number of days in month using if else.
How to print number of days in a given month using if else in C programming.
Logic to find number of days in a month in C program.*/
#include<stdio.h>
int main(){
    int month,year,days;
    scanf("%d%d",&month,&year);
    if(year%4!=0 || (year%100==0 && year%400!=0)){
        days = 28;
    }
    else{days=29;}

    switch(month){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: printf("31 Days");
        break;
        case 2: printf("%d Days",days);
        break;
        default: printf("30 Days");
    }
    return 0;
}