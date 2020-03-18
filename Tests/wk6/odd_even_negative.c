//Made by Aniket Chavan (z5265106) (chavaniket@outlook.com)
//Made on the 2nd April 2019
//Takes 10 integer inputs and outputs two rows of the even and odd numbers

#include <stdio.h>

int main(void) {
    int integer = 1;
    int even[1000] = {0};
    int odd[1000] = {0};
    int j = 0;
    int k = 0;
    
    while (integer > 0) {
        scanf("%d",&integer);
        if (integer > 0) {
            if (even[j] == 0 && integer%2 == 0) {
                even[j] = integer;
            }
            if (odd[k] == 0 && integer%2 == 1) {
                odd[k] = integer;
            }
            if (even[j] != 0) {
                j++;
            } else if (odd[k] != 0) {
                k++;
            }
        }
    }
    printf("Odd numbers were: ");
    for (int i = 0;i < k;i++) {
        printf("%d ",odd[i]);
    }
    printf("\n");
    
    printf("Even numbers were: ");
    for (int i = 0;i < j;i++) {
        printf("%d ",even[i]);
    }
    printf("\n");
    
}
