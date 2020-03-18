//Made by Aniket Chavan (chavaniket@outlook.com)
//Created on the 14th March, 2019
//To take input of size and print out a danish flag in ratio to that size

#include <stdio.h>

int main (void) {
    
    int size;
    printf("Enter the flag size: ");
    scanf("%d", &size);
    int mid = (size/2)+1;
    
    int width  = size*9;
    int height = size*4;
    int heightDiff = (2*size)-1; //How many rows of hash's should be before the horizontal line
    int leftWidthDiff = (3*(size-1))+2; //How many hash's should be on the left of the vertical line
    
    for (int i=1;i<=height;i++) {
        for (int j=1;j<=width;j++) {
            if(i<=heightDiff) {
                if(j<=leftWidthDiff) {
                    printf("#");
                } else if(j==(3*size) || j==(3*size+1)) {
                    printf(" ");
                } else {
                    printf("#");
                }
            } else if(i==(2*size) || i==(2*size+1)) {
                printf(" ");
            } else if(i>(height-heightDiff)) {
                if(j<=leftWidthDiff) {
                    printf("#");
                } else if(j==(3*size) || j==(3*size+1)) {
                    printf(" ");
                } else {
                    printf("#");
                }
            }   
        }
        printf("\n");
    }
    
    return 0;
}
