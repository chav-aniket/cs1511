// COMP1511 Week 5 Lab: Vector Distance
//
// This program was written by Aniket Chavan (z5265106)
// on 22nd of March 2019
//
// This program calculates the euclidean distance between two vectors
//

#define MAX_VEC_SIZE (1000)


#include <stdio.h>
#include <math.h>

int main(void) {
   
    int size;
    double sum = 0;
    
    printf("Enter vector length: ");
    scanf("%d", &size);
    
    double aOne[MAX_VEC_SIZE] = {0};
    double aTwo[MAX_VEC_SIZE] = {0};
    
    printf("Enter vector 1: ");
    for (int i=0;i<size;i++) {
        scanf("%lf", &aOne[i]);
    }
    
    printf("Enter vector 2: ");
    for (int i=0;i<size;i++) {
        scanf("%lf", &aTwo[i]);
    }
    
    for (int i=0;i<size;i++) {
        sum += (aOne[i]-aTwo[i])*(aOne[i]-aTwo[i]);
    }
    
    double dist = sqrt(sum);
    printf("Euclidean distance = %.6lf\n", dist);
    
}
