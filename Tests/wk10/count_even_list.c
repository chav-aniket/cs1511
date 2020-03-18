//Made by Aniket Chavan (z5265106) (chavaniket@outlook.com) on 29-04-19
//Counts the number of even numbers in a linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int count_even(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = count_even(head);
    printf("%d\n", result);

    return 0;
}


// return the number of even values in a linked list
int count_even(struct node *head) {
    struct node *tmp = head;
    int counter = 0;
    
    while (tmp != NULL) {
        if (tmp->data%2==0) counter++;
        tmp = tmp->next;
    }
    return counter;
}


// DO NOT CHANGE THIS FUNCTION

// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}
