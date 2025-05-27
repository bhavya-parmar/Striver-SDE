#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

/*
Init 2 ptrs, p and q.
p increments by 1, q increments by 2.
If p and q meet at some point, it means there is a cycle.
If q reaches the end of the list, it means there is no cycle.
*/

bool hasCycle(struct ListNode *head) {
    if (head==NULL || head->next==NULL) return 0;
    struct ListNode *p = head, *q = head;
    while (q!=NULL && q->next!=NULL) {
        p = p->next;
        q = q->next->next;
        if (p==q) return 1;
    }
    return 0;
}