//Made by Aniket Chavan; z5265106
//Created on the 27th February, 2019
//Designed to take an ipnut of an age
// and output the dating range of that individual
// in accordance to our algorithm

#include <stdio.h>

int year;

int main(void) {
    printf("Enter Year: ");
    scanf("%d",&year);

    int a=year%19;
    int b=year/100;
    int c=year%100;
    int d=b/4;
    int e=b%4;
    int f=(b+8)/25;
    int g=(b-f+1)/3;
    int h=(19*a+b-d-g+15)%30;
    int i=c/4;
    int k=c%4;
    int l=(32+2*e+2*i-h-k)%7;
    int m=(a+11*h+22*l)/451;
    // 3 is March, 4 is April
    int month =(h+l-7*m+114)/31;
    int p=(h+l-7*m+114)%31;
    // Date in Easter Month
    int date = p+1;
    
    if (month == 3) {
        printf("Easter is March %d in %d.\n", date, year);
    }
    else if (month == 4) {
        printf("Easter is April %d in %d.\n", date, year);
    }
    return 0;
}
