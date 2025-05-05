/*•	Write a C program to check whether an alphabet is vowel or consonant using if else.
How to check vowels and consonants using if else in C programming.
C Program to input a character from user and check whether it is vowel or consonant.
Logic to check vowel or consonant in C programming*/

#include<stdio.h>
#include<ctype.h>
int main(){
    char x;
    scanf("%c",&x);
    x=toupper(x);

    switch(x){
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U': printf("Vowel");
        break;
        default: printf("CDIIII");
    }

}