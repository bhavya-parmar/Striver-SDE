#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

/*
Init 2 ptrs A and B at the start of their respective LLs.
If A reaches the end of LL A, it is set to the start of LL B and vice-versa.
If A and B meet at some point, it means there is an intersection.
If they meet, we return the node where they meet. (If they don't meet, they meet at NULL after traversing both lists completely.)
*/

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *A = headA, *B = headB;
    while (A!=B) {
        A = (A==NULL) ? headB : A->next;
        B = (B==NULL) ? headA : B->next;
    }
    return A;
}

// Another logic is that we can find the lengths of both LLs, then move the pointer of the longer LL by the difference in lengths, and then move both pointers until they meet. But this logic is less efficient than the above one. 