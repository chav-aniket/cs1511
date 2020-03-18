//
// Created by chavaniket on 7/05/2019.
//

// Linked List Joining Lists (DN level question)

// Sometimes we want to join lists together and sometimes we want to interweave them,
//  your job is to build something that does exactly that.  Note: you can't edit the original lists

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

// howMany refers to how many elements of one list do you put before going to the next list
// for example if howMany = 1 then you take one element from each list interweaving it
// if howMany = -1 then you put all of listA then all of listB
// Examples (using array syntax to make it easier to demonstrate it but it is linked lists not arrays):
// - joinList([1, 2, 1], [3, 4, 3], -1)  ==  [1, 2, 1, 3, 4, 3]
// - joinList([1, 2, 1], [3, 4, 3], 1)   ==  [1, 3, 2, 4, 1, 3]
// - joinList([1, 2, 1], [3, 4, 3], 2)   ==  [1, 2, 3, 4, 1, 2]
// - joinList([1, 2, 1], [3, 4, 3], 3)   ==  [1, 2, 1, 3, 4, 3]
// You can presume howMany != 0 and howMany == -1 or howMany in [1, max(len(A), len(B))]
// i.e. either it is -1 or it is < the maximum length of the two lists (and not 0)
// you can also presume both lists aren't empty
struct node *join_lists(struct node *listA, struct node *listB, int howMany) {
    struct node *tmp_one = listA;
    struct node *tmp_two = listB;
    struct node *new_head = NULL;
    struct node *tmp;
    
    int null_reached = 0;
    printf("howMany is: %d\n", howMany);
    if (howMany == -1) {
        while (tmp_one != NULL) {
            if (new_head == NULL) {
                new_head = tmp_one;
                tmp = new_head;
                tmp_one = tmp->next;
            }
            tmp->next = tmp_one;
            tmp_one = tmp_one->next;
            tmp = tmp->next;
        }
        while (tmp_two != NULL) {
            tmp->next = tmp_two;
            tmp_two = tmp_two->next;
            if (tmp_two == NULL) {
                tmp = tmp->next;
                tmp->next = NULL;
            } else {
                tmp = tmp->next;
            }
        }
        return new_head;
    }
    while (!null_reached) {
        for (int i = 0; i <= howMany; i++) {
            if (new_head == NULL) {
                new_head = tmp_one;
                tmp = new_head;
                tmp_one = tmp_one->next;
            } else {
                tmp->next = tmp_one;
                tmp_one = tmp_one->next;
            }
            printf("tmp_one is: %d\n", tmp_one->data);
            if (tmp_one == NULL) break;
        }
        for (int i = 0; i <= howMany; i++) {
            tmp = tmp_two;
            tmp_two = tmp_two->next;
            if (tmp_two == NULL) {
                tmp = tmp->next;
                tmp->next = NULL;
                break;
            } else {
                tmp = tmp->next;
            }
        }
        if (tmp_one == NULL && tmp_two == NULL) null_reached = 1;
    }
    tmp = new_head;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
    }
    tmp->next = NULL;
    return new_head;
}

// create linked list from array of strings
// This is to make tests easier;
// DO NOT USE THIS YOU DON'T HAVE TO
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
        i = i-1;
    }
    return head;
}

void assert_list(struct node *head, int result[], int len) {
    int i = 0;
    while (i < len) {
        assert(head != NULL);
        printf("%d\n",head->data);
        assert(head->data == result[i]);
        head = head->next;
        i++;
    }
    assert(head == NULL);
}

int main(void) {
    char *list1[] = {"1", "2", "1"};
    struct node *a = strings_to_list(3, list1);
    char *list2[] = {"3", "4", "3"};
    struct node *b = strings_to_list(3, list2);
    struct node *head = join_lists(a, b, -1);
    int test1[] = {1, 2, 1, 3, 4, 3};
    assert_list(head, test1, 6);
    printf("Test 1 Passed\n");
    head = join_lists(a, b, 1);
    int test2[] = {1, 3, 2, 4, 1, 3};
    assert_list(head, test2, 6);
    printf("Test 2 Passed\n");
    head = join_lists(a, b, 2);
    int test3[] = {1, 2, 3, 4, 1, 3};
    assert_list(head, test3, 6);
    printf("Test 3 Passed\n");
    head = join_lists(a, b, 3);
    int test4[] = {1, 2, 1, 3, 4, 3};
    assert_list(head, test4, 6);
    printf("Test 4 Passed\n");
    printf("All Joining Tests Passed!\n");
    return 0;
}

