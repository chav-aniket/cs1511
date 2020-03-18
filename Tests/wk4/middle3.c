//Made by Aniket Chavan (chavaniket@outlook.com)
//Created on the 18th of March 2019
//Takes three inputs and outputs the middle integer

#include <stdio.h>

int main(void) {
    int one;
    int two;
    int three;
    printf("Enter integer: ");
    scanf("%d", &one);
    
    printf("Enter integer: ");
    scanf("%d", &two);
    
    printf("Enter integer: ");
    scanf("%d", &three);
    
    if (one == two && two == three) {
        printf("Middle: %d\n", one);
    } else if (one == two && two != three) {
        printf("Middle: %d\n", one);
    } else if (two == three && one != two) {
        printf("Middle: %d\n", two);
    } else if (one == three && one != two) {
        printf("Middle: %d\n", one);
    } else if ((one > two && two > three) || (three > two && two > one)) {
        printf("Middle: %d\n", two);
    } else if ((two > one && one > three) || (three > one && one > two)) {
        printf("Middle: %d\n", one);
    } else if ((one > three && three > two) || (two > three && three > one)) {
        printf("Middle: %d\n", three);
    }
}
