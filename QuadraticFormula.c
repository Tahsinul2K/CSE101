/*Write a C program to find all roots of a quadratic equation using if else. 
How to find all roots of a quadratic equation using if else in C programming.
 Logic to find roots of quadratic equation in C programming.*/

 #include<stdio.h>
 #include<math.h>
 int main(){
    float a,b,c;
    float discriminant,sol1,sol2;

    scanf("%f%f%f",&a,&b,&c);
    discriminant= (b*b) - 4*a*c;
    if(discriminant<0)
    printf("cdi");
    else{
        sol1 = (-b+sqrt(discriminant))/(2*a);
        sol2 = (-b-sqrt(discriminant))/(2*a);
        printf("%f %f",sol1,sol2);
    }
    return 0;
 }