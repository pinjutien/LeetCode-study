#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <string>

using namespace std;


// expression tree

// struct node {
//   string element;
//   node *left = NULL;
//   node *right = NULL;
// };

class node {
public:
  string element;
  node *left = NULL;
  node *right = NULL;
  node(string a) { element = a;}
}


int to_int(string input) {
  // "12" = 1* 10 + 2*1
  int num = 0;
  int base = 10;
  for (int i = 0; i < input.size(); i++) {
    num = num*base + ((int)input[i] - 48);
  }

  return num;
}



int eval_expressrion_tree(node *root) {
  if (root == NULL) return 0;
  
  if ((root->right == NULL) & (root->left == NULL)) {
    return to_int(root->elment);
  }

  int LHS = eval_expressrion_tree(root->left);
  int RHS = eval_expressrion_tree(root->right);

  if (root->element == "+") {
    return (LHS + RHS);
  }

  if (root->element == "-") {
    return (LHS - RHS);
  }

  if (root->element == "*") {
    return (LHS * RHS);
  }

  if (root->element == "/") {
    return (LHS/ RHS);
  }  

  return -9999;

}



int main() {
  node *root = new node("+");

  root->left = new node("*");
  root->left->left = new node("2");
  root->left->right = new node("3");

  root->right = new node("-");
  root->right->left = new node("5");
  root->right->right = new node("3");

  cout << "result: " << eval_expressrion_tree(root) << "\n";

}


