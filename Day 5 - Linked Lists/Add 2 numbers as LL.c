#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};
 

struct ListNode* newNode(int v) {
    struct ListNode *node;
    node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = v;
    node->next = NULL;
    return node;
}

struct ListNode* insertNodeEnd(struct ListNode *head, int v) {
    struct ListNode *node = newNode(v);
    if (head==NULL) {
        return node;
    }
    struct ListNode *temp = head;
    while (temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = node;
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;
    struct ListNode *l3 = NULL;
    while (l1!=NULL || l2!=NULL) {
        if (l1==NULL && l2!=NULL) {
            sum = l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            l3 = insertNodeEnd(l3, sum);
            l2 = l2->next;
        } 
        else if (l1!=NULL && l2==NULL) {
            sum = l1->val + carry;
            carry = sum/10;
            sum = sum%10;
            l3 = insertNodeEnd(l3, sum);
            l1 = l1->next;
        }
        else {
            sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum%10;
            l3 = insertNodeEnd(l3, sum);
            l1 = l1->next;
            l2 = l2->next;
        }
    }
    if (carry!=0) {
        l3 = insertNodeEnd(l3, carry);
        return l3;    
    }
    return l3;    
};

// A more compact version of the above function
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;
    struct ListNode *l3 = NULL;
    while (l1!=NULL || l2!=NULL || carry!=0) {
        int val1 = (l1!=NULL) ? l1->val : 0;
        int val2 = (l2!=NULL) ? l2->val : 0;

        sum = val1 + val2 + carry;
        carry = sum/10;
        sum = sum%10;

        l3 = insertNodeEnd(l3, sum);

        if (l1!=NULL) l1 = l1->next;
        if (l2!=NULL) l2 = l2->next;
    }
    if (carry!=0) {
        l3 = insertNodeEnd(l3, carry);
        return l3;    
    }
    return l3;    
};