//Stupid challenge attempted by Aniket Chavan on the 8th March 2019
//Takes three number inputs and orders them from smallest to largest

#include <stdio.h>

int main (void) {
    int a;
    int b;
    int c;
    
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    
    int maxOne = (a>=b)*a + (b>a)*b;
    int maxTwo = (b>=c)*b + (c>b)*c;
    int max = (maxOne>=maxTwo)*maxOne + (maxTwo>maxOne)*maxTwo;
    
    int minOne = (a<=b)*a + (b<a)*b;
    int minTwo = (b<=c)*b + (c<b)*c;
    int min = (minOne<=minTwo)*minOne + (minTwo<minOne)*minTwo;
    
    /*int mid = ((a<=max)*a*(min<a)) + ((a<max)*a*(min<=a)) + ((a<=max)*a*(min<=a)) +
              ((b<=max)*b*(min<b)) + ((b<max)*b*(min<=b)) +
              ((c<=max)*c*(min<c)) + ((c<max)*c*(min<=c)); */
    int mid = (a+b+c) - max-min;
    
    printf("The integers in order are: %d %d %d\n", min, mid, max);
    
    return 0;
}
