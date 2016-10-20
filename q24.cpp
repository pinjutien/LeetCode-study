#include<stdio.h>
#include<stdlib.h>

// ref: http://www.geeksforgeeks.org/pairwise-swap-elements-of-a-given-linked-list/
// linked list node
struct node {
	int val;
	struct node *next;
}

// swap function
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;		
}

// swap node pairwisely
void pairqwiseswap(struct node *head) {
	struct node *temp = head;
	while (temp != NULL && temp->next !=NULL) {
		swap(&temp->val, &temp->next->val);
		temp = temp->next->next;
	}
}

// add a node at the beginning of linked list
void push(struct node **head_ref, int new_data) {
  struct node *new_node = new node;
  new_node->val = new_data;
  new_node -> next = *head_ref;
  *head_ref = new_node;
}

void printList(struct node *node) {


}






