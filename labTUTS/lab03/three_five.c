//Made by Aniket Chavan, contact at chavaniket@outlook.com
//Created on the 5th of March, 2019
//Prints out all numbers divisible by 3 and 5 between zero and the input

#include <stdio.h>

int main(void) {

    int input;

    printf("Enter number: ");
    scanf("%d", &input);
    
    for (int i = 1; i < input; i++) {
        if(i%3 == 0) {
            printf("%d\n", i);
        } else if (i%5 == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
