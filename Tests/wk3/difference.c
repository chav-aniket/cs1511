//Made by Aniket Chavan, contact at chavaniket@outlook.com
//Created on the 5th of March, 2019
//Prints out the difference between two integers

#include <stdio.h>

int main(void) {
    
    int intOne;
    int intTwo;    
    int res;
    
    scanf("%d %d", &intOne, &intTwo);
    res = intOne - intTwo;
    if(res < 0) {
        printf("%d\n", res*(-1));
    } else if (res == 0) {
        printf("equal\n");
    } else {
        printf("%d\n", res);
    }
    
    return 0;
}
