// Made by Aniket Chavan on the 1st of March
// contact at chavaniket@outlook.com
// Takes an ice cream order and tells you if you have enough money

#include <stdio.h>

int main(void) {
    int scoop;
    int cost;
    
    printf("How many scoops? ");
    scanf("%d", &scoop);
    
    printf("How many dollars does each scoop cost? ");
    scanf("%d", &cost);

    if ((cost*scoop) <= 10) {
        printf("You have enough money!\n");
        }
    else if ((cost*scoop) > 10) {
        printf("Oh no, you don't have enough money :(\n");
        }
    return 0;
}

