#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// We can merge two sorted linked lists by using a dummy node to keep track of the merged list.
// We can then iterate through both lists, comparing the values of the nodes and adding the smaller one to the merged list. We continue this process until we reach the end of one of the lists, at which point we can simply append the remaining nodes from the other list.
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    if (list1) tail->next = list1;
    if (list2) tail->next = list2;

    return dummy.next;
}

/*
Before merge:
[dummy] --> NULL
  ^
 tail

After adding first node:
[dummy] --> [1] --> NULL
              ^
             tail

After adding more:
[dummy] --> [1] --> [2] --> [3] --> ...
                              ^
                             tail

*/