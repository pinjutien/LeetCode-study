#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
  int element;
  node *next;
};

node *deleteK(node *root, int K) {

  if (root == NULL) return root;

  node *temp = root;
  node *prev = NULL;
  int count = 1;
  while(temp !=NULL) {

    if (count == K-1) {
      prev = temp;
    }

    if (count == K) {
      prev->next = temp->next;
      temp = prev->next;
      count = 1;
      free(prev);
    }
    else {
      temp = temp->next;
      count += 1;
    }
  }
  return root;
}


void push(node **root, int x) {
  node *temp = new node;
  temp->element = x;
  temp->next = (*root);
  *root = temp;
}


void printLL(node *ptr_node) {
  while (ptr_node != NULL) {
    cout << ptr_node->element << " ";
    ptr_node = ptr_node ->next;
  }
}


int main() {
  node *root = NULL;
  // 1 2 3 4 5 6 7 8
  push(&root, 8);
  push(&root, 7);
  push(&root, 6);
  push(&root, 5);
  push(&root, 4);
  push(&root, 3);
  push(&root, 2);
  push(&root, 1);

  root = deleteK(root, 3);
  printLL(root);
  return 0;
}

