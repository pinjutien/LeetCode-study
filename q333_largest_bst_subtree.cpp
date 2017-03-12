// http://articles.leetcode.com/largest-binary-search-tree-bst-in
//  The run-time complexity for the bottom-up approach is O(n)

BinaryTree* find_largest_bst(BinaryTree *root) {
  BinaryTree *largest_bst = NULL;
  BinaryTree *child;
  int maxNode = INT_MIN;
  largest_bst_helper(root, INT_MIN, INT_MAX, maxNode, largest_bst);
  return largest_bst;

}

int largest_bst_helper(BinaryTree *node,
		       int &min,
		       int &max,
		       int &maxNodes,
		       BinaryTree *& largest_bst) {
  
  if (node == NULL) return 0;
  bool is_bst = true;

  // left node
  int left_nodes_num = largest_bst_helper(node -> left, min, max, maxNodes, largest_bst);
  // left_nodes_num = 0, its left node is null and we update the current_min by the data.
  int current_min = (left_nodes_num == 0)? node -> data: min ;

  // check if left node is BST
  // the node value must be larger than the max in the left node
  if ((left_nodes_num == -1) || (left_nodes_num > 0 && node->data <= max)) {
    is_bst = false;
  }


  // right node
  int right_nodes_num = largest_bst_helper(node -> right, min, max, maxNodes, largest_bst);
  int current_max = (right_nodes_num == 0)? node -> data: max ;  
  // check if right node is BST
  // the node value must be smaller than the min in the right node
  if ((right_nodes_num == -1) || (right_nodes_num > 0 && node->data >= min)) {
    is_bst = false;
  }

  if (is_bst) {
    min = current_min;
    max = current_max;
    int total_nodes = left_nodes_num + right_nodes_num + 1;
    if (total_nodes > maxNodes) {
      maxNodes = total_nodes;
      largest_bst = node;
    }
    return total_nodes;
  }
  else {
    return -1;
  }

}
