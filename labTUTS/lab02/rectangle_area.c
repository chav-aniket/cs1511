//Made by Aniket Chavan on the 1st of March
//contact at chavaniket@outlook.com
//For the purpose of calculating the area of a rectangle
// given its side lengths

#include <stdio.h>

int length;
int width;

int main(void) {
    printf("Enter the length of the rectangle: ");
    scanf("%d", &length);

    printf("Enter the width of the rectangle: ");
    scanf("%d", &width);
    
    printf("Area = %d\n", length*width);
    
    return 0;
}
    
