//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106)
//Created on the 05/04/19
//Purpose of program is to encrypt a text file given a specific caesar shift

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int swap_case (int character);
int encrypt (int character, int shift);

int main (int argc, char *argv[]) {
    int shift = atoi(argv[1]);
    int c = getchar();
    while (c != EOF) {
        if (c >= 'A' && c <= 'Z') {
            putchar(swap_case(encrypt(swap_case(c),shift)));
        } else if(c >= 'a' && c <= 'z') {
            putchar(encrypt((c),shift));
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

int encrypt (int character, int shift) {
    if (character >= 'a' && character <= 'z') {
        if ((character - 'a' + shift) % 26 >= 0) {
            return (character - 'a' + shift) % 26 + 'a';
        } else if ((character - 'a' + shift) % 26 < 0) {
            return (character - 'a' + shift) % 26 +'a' + 26; 
        }
    } else {
        return character;
    }
    assert(0);
}
