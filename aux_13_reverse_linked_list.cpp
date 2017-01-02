#include <stdio.h>
#include <stdlib.h>

using namespace std;


struct node {
  int element;
  node *next;
};

void resever_linked_list(node **root) {
  node *current = *root;
  node *prev = NULL;
  node *temp;
  
  while (current !=NULL) {
    temp = current ->next;
    current ->next = prev;
    prev = current;
    current = temp;
  }

  *root = prev;
}

void push(node **root, int x) {

  node *temp = new node;
  temp ->element = x;
  
  temp ->next = *root;
  *root = temp;
}
