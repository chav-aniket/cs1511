//Made by Aniket Chavan on the 12-04-19
//contact information: (z5265106) (chavaniket@outlook.com)
//Checks if a string input is a palindrome or not

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CHAR 4096

int checkPal(int length, char array[MAX_CHAR]);

int main(void) {
    printf("Enter a string: ");
    char line[MAX_CHAR];
    fgets(line,MAX_CHAR,stdin);
    int len = strlen(line);
    if (len < 3) {
        printf("String is a palindrome\n");
    } else if (checkPal(len,line)) {
        printf("String is a palindrome\n");
    } else if (!checkPal(len,line)) {
        printf("String is not a palindrome\n");
    }
    return 0;
}

int checkPal(int length, char array[MAX_CHAR]) {
    for (int i = 0;i < length/2+1;i++) {
        if (array[i] != array[length-2-i]) {
            return 0;
        }
    }
    return 1;
}
