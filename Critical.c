#include <stdio.h>

int main() {
    int a = 5, b = 0;

    if (a > 3 || ++b > 0)/*Due to short-circuiting with ||, ++b > 0 is not evaluated So b remains 0 printf: a = 5, b = 0*/
        printf("Condition 1: a = %d, b = %d\n", a, b);

    if (a < 3 && ++b > 0)
        printf("Condition 2: a = %d, b = %d\n", a, b);

    if ((a = 0) || ++b) 
        printf("Condition 3: a = %d, b = %d\n", a, b);
    else
        printf("Condition 3 ELSE: a = %d, b = %d\n", a, b);

    return 0;
       /*(a = 0) sets a to 0, and the expression returns 0 (false)

    So it does evaluate ++b, which becomes 1
    
    The condition becomes 0 || 1 → true
    
    So the if block executes*/
}
