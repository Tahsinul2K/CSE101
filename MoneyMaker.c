/*Write a C program to input amount from user and print minimum number of notes 
(Rs. 500, 100, 50, 20, 10, 5, 2, 1) required for the amount. 
How to the minimum number of notes required for the given amount in C programming. 
Program to find minimum number of notes required for the given denomination.
Logic to find minimum number of denomination for a given amount in C program*/

#include<stdio.h>
int main(){
    int value, note500,note100,note50,note20,note5;
    scanf("%d",&value);
    note500= value/500;
    value= value%500;

    note100= value/100;
    value= value%100; 

    note50= value/50;
    value= value%50;

    note20= value/20;
    value= value%20;

    note5= value/5;
    value= value%5;

    printf("500 = %d 100 = %d 50 = %d 20 = %d 5 = %d",note500,note100,note50,note20,note5);
    return 0 ;
}