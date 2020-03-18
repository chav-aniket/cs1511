// Made by Aniket Chavan on the 1st of March
// contact at chavaniket@outlook.com
// Takes two integer inputs and adds them together
// outputs the entire equation

#include <stdio.h>

int main(void) {
    int n;
    int m;
    
    printf("Please enter two integers: ");
    scanf("%d %d",&n,&m);
    
    int res = n + m;
    
    printf("%d + %d = %d\n", n, m, res);
    return 0;
}
