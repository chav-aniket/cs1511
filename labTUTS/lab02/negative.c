// Made by Aniket Chavan on the 1st of March
// contact at chavaniket@outlook.com
// Distinguishes between positive and negative values

#include <stdio.h>

int main(void) {
    int val;
    
    scanf("%d",&val);
    if (val > 0) {
        printf("You have entered a positive number.\n");
        }
    else if (val < 0) {
        printf("Don't be so negative!\n");
        }
    else if (val == 0) {
        printf("You have entered zero.\n");
        }
    
    return 0;

} 
