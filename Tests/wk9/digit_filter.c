//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106) on 23-03-19
//This program replaces every character other than digits 0-9 with a full stop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void) {
    int c = getchar();
    while (c != EOF) {
        if ((c >= '0' && c <= '9') || c == ' ') {
            putchar(c);
        } else if (c == '\n') {
            printf("\n");
        } else {
            printf(".");
        }
        c = getchar();
    }
    return 0;
}
