//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106) on 23-03-19
//This program maps every digit from 0-9 to a letter as inputted

#include <stdio.h>
#include <stdlib.h>

int main (int argc,char *argv[]){
    int c = getchar();
    while (c != EOF) {
        if (c >= '0' && c<= '9') {
            printf("%c",argv[1][c-48]);
        } else if (c == '\n') {
            printf("\n");
        } else {
            putchar(c);
        }
        c = getchar();
    }
    return 0;
}
