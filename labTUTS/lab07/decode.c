//Made my Aniket Chavan (z5265106) (chavaniket@outlook.com)
//Made on the 12/04/19
//Decrypt substitution encryption

#include <stdio.h>
#include <stdlib.h> 

int swap_case(int character);
int findIndex (int number, char array[]);

int main(int argc, char *argv[]) {
    //printf("%s\n",argv[1]);
    int value;
    int c = getchar();
    while (c != EOF) {
        if (c >='A' && c <= 'Z') {
            value = findIndex(swap_case(c),argv[1]);
            c = swap_case(value + 'a');
            putchar(c);
        } else if (c >= 'a' && c <= 'z') {
            value = findIndex(c,argv[1]);
            putchar(value + 'a');
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

int findIndex (int number, char array[]) {
    for (int i = 0;i < 26;i++) {
        if (number == array[i]) {    
            return i;
        }
    }
    return 0;
}
