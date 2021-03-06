//Made by Aniket Chavan (z5265106) (chavaniket@outlook.com)
//Made on the 2nd April 2019
//Takes a stream of inputs and prints out every input which is not divisible
//by any other previous input

#include <stdio.h>

int input[1000] = {0};
int filter[1000] = {0};


int main(void) {
    int factorFound = 0;
    int inputLen = 0;
    int integer;
    
    for (int i = 0;i<1000;i++) {
        if (scanf("%d",&integer) > 0) {
            input[i] = integer;
            inputLen++;
        } else {
            break;
        }
    }
    int c = 0;
    for (int i = 0;i<inputLen;i++) {
        factorFound = 0;
        for (int j = 0;j<inputLen;j++) {
            if (input[i]%input[j] == 0 && i!=j) {
                factorFound = 1;
            }
        }
        if(!factorFound) {
            filter[c] = input[i];
            c++;
        }
    }
    printf("Indivisible numbers: ");
    for (int k = 0;k<inputLen && filter[k]!=0;k++) {
        printf("%d ",filter[k]);
    }
    printf("\n");
}
