//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106) on 23-03-19
//This program reads the input and prints out a count of:
// the characters, words and lines

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    
    int c = getchar();
    int b = 0;
    while (c != EOF) {
        char_count++;
        
        if (c == '\n') {
            line_count++;
        } else if ( (b == 0 && c != ' ' && c != '\n') ||
                    ((b == ' ' || b == '\n') && 
                    (c != ' ' && c != '\n')) ) {
            word_count++;
        }
        b = c;
        c = getchar();
    }
    printf("%d lines %d words %d characters\n",line_count,word_count,char_count);
    return 0;
}
