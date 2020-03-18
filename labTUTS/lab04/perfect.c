//Made by Aniket Chavan (chavaniket@outlook.com)
//Created on the 14th March, 2019
//Purpose is to take a number and distinguish whether it is perfect or not

#include <stdio.h>

int main(void) {
    int persum = 0;
    int n;
    
    printf("Enter number: ");
    scanf("%d", &n);
    printf("The factors of %d are:\n", n);
    
    
    for (int i=1;i<=n;i++) {
        if(n%i==0) {
            printf("%d\n", i);
            persum = persum + i;
        }
    }
    printf("Sum of factors = %d\n", persum);
    if((persum/2)==n) {
        printf("%d is a perfect number\n", n);
    } else {
        printf("%d is not a perfect number\n", n);
    }
    return 0;
}
