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
	node *temp = root;
	node *ptr;
	int count;
	
	if ((root == NULL) || (K ==0)) return root;
	
	if (K ==1) {
		while (root !=NULL) {
			// ptr = root;
			root = root->next;
			// free(ptr);
		}
		return root;
	}
	
	while ((temp !=NULL) && (temp->next !=NULL)) {
		count = K-1;
		// keep proceeding and stop at the previous step of the Kth node.
		while ((count != 1) && (temp ->next != NULL)) {
			temp = temp->next;
			count -= 1;
		}
		
		if (temp->next == NULL) {
			break;
		}
		
		// count =1: temp->next is the node we want to remove. 
		ptr = temp->next;
		temp->next = ptr->next;
		free(ptr);
		temp = temp->next;
		
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
	node *result_temp = NULL;
	// 1 2 3 4 5 6 7 8
	// push(&root, 8);
	// push(&root, 7);
	push(&root, 6);
	push(&root, 5);
	push(&root, 4);
	push(&root, 3);
	push(&root, 2);
	push(&root, 1);
	
	result_temp = deleteK(root, 3);
	// result_temp = deleteK(root, 1);
	printLL(result_temp);
	return 0;
}

