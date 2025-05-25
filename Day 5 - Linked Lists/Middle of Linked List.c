#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct node {
    int val;
    struct node *next;
};

// Using Count

struct node* middleNode(struct node* head) {
    int c = 0;
    struct node *temp = head;
    while (temp!=NULL) {
        temp = temp->next;
        c+=1;
    }
    for (int i=0; i<(c/2); i++){
        head = head->next;
    }
    return head;
}

// Without using count

/* 
We initialize 2 pointers i and j and traverse the linked list,
i increments by 1,
j increments by 2.
Therefore when j reaches the end of linked list, i will be at the middle.
*/

struct node* middleNode(struct node* head) {
    struct node *i = head, *j = head;
    while (j!=NULL && j->next!=NULL) {
        i = i->next;
        j = j->next->next;
    }
    return i;
    
}