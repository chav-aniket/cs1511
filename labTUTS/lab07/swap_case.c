//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106)
//Created on the 05/04/19
//Purpose of program is to reprint each character in the opposite case

#include <stdio.h>

int swap_case(int character);

int main (void) {
    int c = getchar();
    while (c != EOF) {
        putchar(swap_case(c));
        c = getchar();
    }
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
