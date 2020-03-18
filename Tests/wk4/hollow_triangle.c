//Made by Aniket Chavan (chavaniket@outlook.com)
//Created on the 19th of March 2019
//Takes a size input to print out a hollow triangle for that size

#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    for (int i = 1;i<=size;i++) {
        for (int j = 1;j<=size;j++) {
            if(j == 1 || j == i || i == size) {
                printf("*");
            } else {
                printf(" ");
            }
        }
    printf("\n");
    }
    
    
}
