//Made by Aniket Chavan, contact chavaniket@outlook.com
//Developed on the 5th of March, 2019
//Purpose of code is to order the code from smallest to largest

#include <stdio.h>

int digOne;
int digTwo;
int digThree;

int main(void) {
    
    printf("Enter integer: ");
    scanf("%d", &digOne);
    
    printf("Enter integer: ");
    scanf("%d", &digTwo);
    
    printf("Enter integer: ");
    scanf("%d", &digThree);
    
    if (digOne <= digTwo && digOne <= digThree) {
        if(digTwo < digThree) {
            printf("The integers in order are: %d %d %d\n", digOne, digTwo, digThree);
        } else if (digThree <= digTwo) {
            printf("The integers in order are: %d %d %d\n", digOne, digThree, digTwo);
    }} else if (digTwo <= digOne && digTwo <= digThree) {
        if(digOne <= digThree) {
            printf("The integers in order are: %d %d %d\n", digTwo, digOne, digThree);
        } else if (digThree <= digOne) {
            printf("The integers in order are: %d %d %d\n", digTwo, digThree, digOne);
    }} else if (digThree <= digOne && digThree <= digTwo) {
        if(digOne <= digTwo) {
            printf("The integers in order are: %d %d %d\n", digThree, digOne, digTwo);
        } else if (digTwo <= digOne) {
            printf("The integers in order are: %d %d %d\n", digThree, digTwo, digOne);
    }}
    return 0;
}
