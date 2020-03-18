#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

struct node *reverse(struct node *head);
struct node *strings_to_list(int len, char *strings[]);
void print_list(struct node *head);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    struct node *new_head = reverse(head);
    print_list(new_head);

    return 0;
}

//
// Place the list pointed to by head into reverse order.
// The head of the list is returned.
//
struct node *reverse(struct node *head) {
    int list_len = 0;
    struct node *tmp = head;
    struct node *new_head = NULL;
    struct node *new_tmp = new_head;
    
    while (tmp != NULL) {
        list_len++;
        tmp = tmp->next;
    }
    for (int i = 1; i < list_len; i++) {
        tmp = head;
        int counter = 0;
        while (counter != list_len - i) {   
            tmp = tmp->next;
            counter++;
        }
        if (new_head == NULL) {
            new_head = tmp;
            new_head->next = NULL;
        }
        new_tmp = new_head;
        while (new_tmp->next != NULL) { 
            new_tmp = new_tmp->next;
        }
        new_tmp->next = tmp;
    }
    return new_head;
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

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}


