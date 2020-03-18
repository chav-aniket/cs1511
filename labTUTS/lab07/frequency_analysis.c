//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106)
//Created on the 05/04/19
//Purpose of program is to print out the frequency of each letter in a text

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 26

int make_lower(int character);
void printFunction(int letter);

int main(void) {
    int c = getchar();
    double input[MAX_LENGTH] = {0};
    double letterSum = 0;
    while (c != EOF) {
        if(c >= 'A' && c <= 'Z') {
            c = make_lower(c);
            input[c-'a']++;
            letterSum++;
        } else if (c >= 'a' && c <= 'z') {
            input[c-'a']++;
            letterSum++;
        }
        c = getchar();
    }
    for (int i = 0; i < MAX_LENGTH;i++) {
        printf("'%c' %.6lf %.0lf\n", 'a'+i, input[i]/letterSum, input[i]);
    }
    return 0;
}



int make_lower(int character) {
    if (character >= 'A' && character <= 'Z') {
        int alphabetPosition = character - 'A';
        return 'a' + alphabetPosition;
    } else {
        return character;
    }
}
