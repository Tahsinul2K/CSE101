/*Take four characters as input and output how many
given characters were numbers.
*/
#include<conio.h>
#include<stdio.h>
int main(){
    char x;
    int i, count=0;
    for(i=1;i<=4;i=i+1){
        scanf("%c%*c",&x); /*it takes space as an input*/
        if(x>=48 && x<=57){
            count++;
        }
    }
    printf("There are %d digits",count);
    return 0;
}