#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct node {
    int val;
    struct node *next;
};

// Iterative method
struct node *reverse(struct node *head) {
  struct node *left = NULL, *right = NULL;
  while (head != NULL) {
    right = head -> next;
    head -> next = left;
    left = head;
    head = right;
  }
  head = left;
  return head;
}

// Recursive method
struct node *recursive_reverse(struct node* head) {
    if (head==NULL) {
        return head;
    }
    struct node *newHead = head;
    if (head->next!=NULL) {
        newHead = recursive_reverse(head->next);
        head->next->next = head;
    }
    head->next = NULL;
    return newHead;
}