//Made by Aniket Chavan, contact at chavaniket@outlook.com
//Created on the 5th of March, 2019
//takes 3 float inputs and outputs whether they are a triangle by rule:
//      3 numbers are a triangle if the sum of any 2 numbers is greater than the third

#include <stdio.h>

int main(void) {

    float one;
    float two;
    float three;

    printf("Please enter three numbers: ");
    scanf("%f %f %f", &one, &two, &three);
    
    if (one+two>three && one+three>two && two+three>one) {
        printf("triangle");
    } else {
        printf("not a triangle");
    }
    
    return 0;
}
