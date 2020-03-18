//Made by Aniket Chavan, contact at chavaniket@outlook.com
//Created on the 5th of March, 2019
//For the purpose of identifying if a year is a leap year

#include <stdio.h>

int main(void) {
    
    int year;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    if (year%400 == 0) {
        printf("%d is a leap year.\n", year);
    } else if (year%100 == 0) {
        printf("%d is not a leap year.\n", year);
    } else if (year%4 == 0) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }
    
    return 0;
}
