//Made by Aniket Chavan on the 24th of March (chavaniket@outlook.com)
//reads one input and prints out its prime factorisation

#include <stdio.h>

int primeChecker (int n) {
    int factorFound = 0;
    for (int i = 2; i < n; i++) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    int number;
    
    printf("Enter number: ");
    scanf("%d", &number);
    int remainder = number;
    
    if(primeChecker(number)) {
        printf("%d is prime\n", number);
    } else {
        printf("The prime factorization of %d is: \n", number);
        for (int i = 2; i < remainder; i++) {
            if (remainder%i == 0 && primeChecker(i)) {
                printf("%d * ", i);
                remainder = remainder/i;
                i = 1;
            }
        }
        printf("%d = %d\n",remainder, number);
    }
}
