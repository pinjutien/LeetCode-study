#include <stdio.h>
#include <stdlib.h>
// ref: https://github.com/zrwwzr/Leetcode-Amazon/blob/master/Reverse%20Second%20Half%20of%20Linked%20List.cpp

struct node {
  int element;
  node *next;
  node(int x): element(x), next(NULL) {}
  
};


node *reverse(node *root) {
  node *current = root;
  node *previous = NULL;
  node *temp;
  
  while (current != NULL) {
    temp = current->next;
    current->next = previous;
    prevous = current;
    current = temp;
  }
  
  return previous;
}

void reverse_2nd_half_linked_list(node *root) {
  node *p1 = root;
  node *p2 = root;
  node *prev = NULL;
  // p2 is faster than p1 than factor 2
  // when p2 is point to NULL, p1 points to the middle element.
  // prev is the pointer to the previous element of the middle element.
  while ((p2 != NULL) & (p2->next->next !=NULL)) {
    prev = p1;
    p1 = p1->next;
    p2 = p2->next->next;
  }

  if (!p2) {
    prev->next = reverse(p1);
  }
  else {
    p1->next = reverse(p1);
  }

  return root;
}

