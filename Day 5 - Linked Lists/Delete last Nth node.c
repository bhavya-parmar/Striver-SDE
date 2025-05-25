#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct node {
    int val;
    struct node *next;
};

// init 2 ptrs, move 1 ptr n steps ahead, then move both ptrs until the first ptr reaches the end.
// When the first ptr reaches the end, the second ptr will be at the nth node from the end.

struct node* removeNthFromEnd(struct node* head, int n) {
    if (head->next==NULL) { // If there is only one node, we return NULL after freeing it.
        free(head);
        return NULL;
    }

    struct node *p = head, *q = head, *temp = NULL;

    while (n!=0) {  // Move q n steps ahead
        q = q->next;
        n--;
    }

    if (q==NULL){   // If q is NULL, it means we need to remove the head node.
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    while (q->next!=NULL) { // Move both pointers until q reaches the end
        p = p->next;
        q = q->next;
    }
    // Now p is at the node before the one we want to remove
    temp = p->next;
    p->next = temp->next;
    free(temp);

    return head;
}