// COMP1511 Week 5 Lab: Vector Permutation
//
// This program was written by Aniket Chavan (z5265106)
// on 22nd of March 2019
//
// This program reorders a vector in a new permutation
//

#include <stdio.h>
#define MAX_VEC_LEN 1000

int main(void) {
    
    int size;
    int perm;
    int print = 1;
    
    printf("Enter vector length: ");
    scanf("%d", &size);
    
    int aOne[MAX_VEC_LEN] = {0};
    int aTwo[MAX_VEC_LEN] = {0};
    int aThree[MAX_VEC_LEN] = {0};
    
    printf("Enter vector: ");
    for (int i=0;i<size;i++) {
        scanf("%d", &aOne[i]);
    }
    
    printf("Enter permutation:");
    for (int i=0;i<size;i++) {
        scanf("%d", &aTwo[i]);
        if (aTwo[i]<0 || aTwo[i]>=size) {
            print = 0;
        }
    }
    
    for (int i=0;i<size;i++) {
        aThree[i] = aOne[aTwo[i]];
    }
    if (print == 1) {
        for (int i=0;i<size;i++) {
            printf("%d", aThree[i]);
        }
        printf("\n");
    } else {
        printf("Invalid permutation\n");
    }
    
}
