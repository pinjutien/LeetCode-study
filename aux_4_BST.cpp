#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct node {
	int key;
	node *left, *right;
};


// new node
node *new_node(int item) {
	node *temp = new node();
	temp ->left = NULL;
	temp ->right = NULL;
	temp -> key = item;
	return temp;
	
}

// search BST if key exist.
// if it did, return the node having the key
// if not, return the closet of node
node *search(node *root, int key) {
	if ( (root == NULL) | (root -> key == key) ) {
		return root;
	}
	
	if (key < root->key) {
		return search(root->left, key);
	}
	
	return search(root->right, key);
}

// insert key into BST tree
// and return node
node *insert(node *node_temp, int item) {
	
	if (node_temp == NULL) return new_node(item);
	
	if (item < node_temp->key) {
		node_temp->left = insert(node_temp->left, item);
	}
	else {
		node_temp->right = insert(node_temp->right, item);
	}
	
	return node_temp;
}

//http://www.geeksforgeeks.org/618/
void inorder(node *root) {
  if (root !=NULL) {
    inorder(root->left);
    cout << root->key << "\n";
    inorder(root->right); 
  }
}


void preorder(node *root) {
  if (root !=NULL) {
    cout << root->key << "\n";
    preorder(root->left);
    preorder(root->right); 
  }
}


void portorder(node *root) {
  if (root !=NULL) {
    postorder(root->left);
    postorder(root->right); 
    cout << root->key << "\n";
  }
}



int main() {
	
	struct node *root = NULL;
	root = insert(root, 5);
	insert(root, 3);
	insert(root, 2);
	insert(root, 4);
	insert(root, 7);
	insert(root, 6);
	insert(root, 8);
	
}

