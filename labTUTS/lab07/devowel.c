//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106)
//Created on the 05/04/19
//Purpose of program is to reprint text input after removing all lower-case vowels

#include <stdio.h>

int is_vowel (int character);

int main(void) {
    int c = getchar();
    while (c != EOF) {
        if(!is_vowel(c)) {
            putchar(c);
        }
        c = getchar();
    }
}

int is_vowel (int character) {
    if (character == 'a' || character == 'e' || character == 'i' || 
        character == 'o' || character == 'u') {
        return 1;
    } else {
        return 0;
    }
}
