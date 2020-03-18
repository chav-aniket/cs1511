//Made by Aniket Chavan on the 24th of March (chavaniket@outlook.com)
//reads two positive integers and calculates the product of all odd integers in between

#include <stdio.h>

int main(void) {
    int lower;
    int upper;
    int sum = 1;
    
    printf("Enter lower: ");
    scanf("%d", &lower);
    
    printf("Enter upper: ");
    scanf("%d", &upper);
    
    for(int i = lower + 1;i < upper; i++) {
        if(i%2 != 0) {
            sum = sum*i;
        }
    }
    printf("%d\n",sum);
}
