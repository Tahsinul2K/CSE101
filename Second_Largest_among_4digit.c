/*Find second largest of 4 digit number*/
#include<stdio.h>
int main(){
    int num,a,b,c,d,max=0, second = -1;
    scanf("%d",&num);
    a=num%10;
    b=(num/10)%10;
    c=(num/100)%10;
    d=(num/1000)%10;
    if(a>b){
        max = a;
        second = b;
    }
    else if(a<b){
        max = b;
        second = a;
    }

    else if(a==b){
        max = a;
    }

    if(c>max){
        second = max;
        max = c;
    }
    else if(c<max && c>second){
        second = c;
    }
    
    if(d>max){
        second = max;
        max = d;
    }
    else if(d<max && d>second){
        second = d;
    }
    printf("%d", second);

    return 0;
}