#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// To delete a given node in a ll (without being given the head of the ll), we can start from the given node and copy the value of the next node into the current node, then move to the next node. We repeat this until we reach the last node, where we set its next pointer to NULL. This effectively deletes the given node from the linked list.
void deleteNode(struct ListNode* node) {
    while (node->next->next!=NULL) {  
        node->val = node->next->val;
        node = node->next;   
    }
    node->val = node->next->val;
    node->next = NULL;
}