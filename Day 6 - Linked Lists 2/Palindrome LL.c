#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to reverse a linked list
struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *l = NULL, *r = NULL;
    while (head!=NULL) {
        r = head->next;
        head->next = l;
        l = head;
        head = r;
    }
    head = l;
    return head;
}

/*
We can use the fast and slow pointer technique to find the middle of the linked list.
Then we reverse the second half of the linked list and compare it with the first half.
*/
bool isPalindrome(struct ListNode* head) {
    if (head==NULL || head->next==NULL) return 1;
    struct ListNode *p = head, *q = head;
    while (q!=NULL && q->next!=NULL) {
        p = p->next;
        q = q->next->next;
    }
    q = head;
    p = reverse(p);
    while (q!=NULL && p!=NULL) {
        if (q->val!=p->val) return 0;
        q = q->next;
        p = p->next;
    }
    return 1;
}