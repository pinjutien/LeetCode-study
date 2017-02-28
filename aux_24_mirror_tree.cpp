#include<stdio.h>
#include<stdlib.h>

// http://www.binarycoder.org/data-structure/mirror-image-binary-tree-iterative/
// http://www.geeksforgeeks.org/write-an-efficient-c-function-to-convert-a-tree-into-its-mirror-tree/


struct node {
  int data;
  node *left;
  node *right;
};

node *new_node(int x) {

  node *temp = new node();
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
}


void mirror_tree(node *root) {
  if (root == NULL) {
    return;
  }

  mirror_tree(root->left);
  mirror_tree(root->right);

  // swap left and right subtree
  node *temp_tree = root->left;
  root->left = root->right;
  root->right = temp_tree;
}


void in_order(node *node) {
  if (node == NULL) return;
  in_order(node->left);
  cout << node->data << ' ';
  in_order(node->right);
}
