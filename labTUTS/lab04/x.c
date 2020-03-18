//Made by Aniket Chavan (chavaniket@outlook.com)
//Created on the 14th March, 2019
//Purpose is to take a number, n, and create an n*n print
// of dashes and asterisks which creates a cross design

#include <stdio.h>

int main(void) {
    
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    int mid = (n/2)+1;
    
    int first = 1;
    int last = n;
    
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (j==first||j==last) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
        first = first + 1;
        last = last -1;
    }
    
    return 0;
}
