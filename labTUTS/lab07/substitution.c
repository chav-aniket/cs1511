//Made my Aniket Chavan (z5265106) (chavaniket@outlook.com)
//Made on the 10/04/19
//Encrypt a text using substitution encryption

#include <stdio.h>
#include <stdlib.h>

int swap_case(int character);

int main(int argc, char *argv[]) {
    //printf("%s\n",argv[1]);
    
    int c = getchar();
    while (c != EOF) {
        if (c >='A' && c <= 'Z') {
            c = swap_case(argv[1][swap_case(c)-'a']);
            putchar(c);
        } else if (c >= 'a' && c <= 'z') {
            putchar(argv[1][c-'a']);
        } else {
            putchar(c);
        }
        c = getchar();
    }
    
    return 0;
}

int swap_case(int character) {
    if (character >= 'a' && character <= 'z') {
        int alphabetPosition = character - 'a';
        return 'A' + alphabetPosition;
    } else if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character - 'A';
        return 'a' + alphabetPosition;
    } else {
        return character;
    }
}
