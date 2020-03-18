//Made by Aniket Chavan (chavaniket@outlook.com) (z5265106)
//Made on the 16-04-19
//Checks an array if there are any duplicates
//returns array without duplicates and number of duplicates found

#include <stdio.h>
#include <stdlib.h>

int remove_duplicates (int length, int source[length], int destination[length]);

int main(void) {
    return 0;
}

int remove_duplicates (int length, int source[length], 
                       int destination[length]) {
    int isDuplicate = 0;
    int count = 0;
    int k = 0;
    
    for (int i = 0;i < length;i++) {
        isDuplicate = 0;
        for (int j = 0;j < length;j++) {
            if (source[i] == destination[j]) {
                isDuplicate = 1;
                count++;
                break;
            }
        }
        if (!isDuplicate) {
            destination[k] = source[i];
            k++;
        }
    }
    return length - count;
}

