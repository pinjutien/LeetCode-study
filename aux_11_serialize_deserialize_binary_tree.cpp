#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};

node *newNode(int x) {
  node *temp = new node;
  temp ->data = x;
  temp ->left = NULL;
  temp ->rigth = NULL;
}

void serialize(node *root, vector<int> &A) {

  if (root == NULL) {
    A.push_back(-1);
  }

  if (root -> left != NULL) {
    serialize(root->left, A);
  }
    
  A.push_back(root->data);

  if (root -> right != NULL) {
    serialize(root->right, A);
  }

}



void deserialize(node* root, vector<int> &A) {

  deserialize(root->left, A);

  int current_first_element = A.front();
  root = newNode(current_first_element);
  A.erase(A.begin());

  deserialize(root->right, A);

}



int main() {


  return 0;
}
