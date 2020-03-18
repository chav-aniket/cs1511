//Made by Aniket Chavan (z5265106) (chavaniket@outlook.com) on 29-04-2019
//Returns the most frequent integer in a linked list
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int most_frequent(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    int result = most_frequent(head);
    printf("%d\n", result);

    return 0;
}


// return the value which occurs most frequently in a linked list
// if several values are equally most frequent
// the value that occurs earliest in the list is returned
int most_frequent(struct node *head) {
    struct node *tmp_one = head;
    struct node *tmp_two = head;
    int prev_freq = 0;
    int frequency = 0;
    int top_freq = head->data;
    
    while (tmp_one != NULL) {
        tmp_two = head;
        frequency = 0;
        while (tmp_two != NULL) {
            if (tmp_one->data == tmp_two->data) frequency++;
            tmp_two = tmp_two->next;
        }
        if (frequency > prev_freq) {
            top_freq = tmp_one->data;
            prev_freq = frequency;
        }
        tmp_one = tmp_one->next;
    }
    return top_freq;
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
