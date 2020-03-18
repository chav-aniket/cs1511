//Made by Aniket Chavan (z5265106) (chavaniket@outlook.com)
//Made on 08/04/2019
//This program takes in a stream of integers and must output every integer
//missing from between the lowest and highest digits

#include <stdio.h>
#define MAX_INT 10000

int main(void) {
    int inputStream[MAX_INT] = {0};
    int smallest = MAX_INT; // An extremely large number which will be decreased
    int largest = 1; // An extremely small number which will increase
    int counter = 0;
    for (int i = 0;i < MAX_INT;i++) {
        scanf("%d",&inputStream[i]);
        if (inputStream[i] <= 0) {
            counter = i;
            break;
        }
        if (inputStream[i] > largest) {
            largest = inputStream[i];
        }

    }
    int matchFound = 0;
    
    for (int i = 1;i < largest;i++) {
        matchFound = 0;
        for (int j = 0;j < counter;j++) {
            if (i == inputStream[j]) {
                matchFound = 1;
                break;
            }
        }
        if (!matchFound) {
            printf("%d ",i);
        }
    }
    printf("\n");
}
