//Made by Aniket Chavan on the 1st of March
//contact at chavaniket@outlook.com
//For the purpose of distinguishing between a pass and fail

#include <stdio.h>

int mark;

int main(void) {
    printf("Please enter your mark: ");
    scanf("%d", &mark);
    
    if (mark < 50 && mark >= 0) {
        printf("FAIL\n");
    }
    else if (mark >= 50 && mark <= 100) {
        printf("PASS\n");
    }
    else {
        printf("ERROR\n");
    }
    return 0;
}
