//Made by Aniket Chavan (chavaniket@outlook.com)
//Created on the 18th of March 2019
//Takes a size input to print out an n tall and n long "L"

#include <stdio.h>

int main(void) {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);
    
    for (int i = 1;i<=size;i++) {
        for (int j = 1;j<=size;j++) {
            if(j == 1) {
                printf("*");
            } else if (i == size) {
                printf("*");
            } else {
                printf(" ");
            }
        }
    printf("\n");
    }
    
    
}
