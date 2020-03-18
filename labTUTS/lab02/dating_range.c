//Made by Aniket Chavan; z5265106
//Created on the 26th February, 2019
//Designed to take an ipnut of an age
// and output the dating range of that individual
// in accordance to our algorithm

#include <stdio.h>

int age;
void date_algo(int age) {
    if (age < 12) {
        printf("You are too young to be dating.\n");
    }
    else {
        int lower = (age/2) + 7;
        int upper = (age-7)*2;
        printf("Your dating range is %d to %d years old.\n", lower, upper);
    }
}

int main(void) {
    printf("Enter your age: ");
    scanf("%d", &age);
    date_algo(age);
}
