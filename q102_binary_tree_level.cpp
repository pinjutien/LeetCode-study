// http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-level-order.html

class Solution {
public:
  vector< vector<int> > levelOrder(TreeNode *root) {
    vector< vector<int> > result;

    if(!root) return result;

    vector<TreeNode*> *current_level = new vector<TreeNode*>();
    vector<TreeNode*> *next_level = new vector<TreeNode*>();
    current_level->push_back(root);

    while(!current_level->empty()) {

      vector<int> current_values;
      for (int i = 0; i < current_level->size(); i++) {
	TreeNode *current_node = (*current_level)[i];
	current_values.push_back(current_node->data);

	if (current_node->left) {
	  next_level->push_back(current_node->left);
	}

	if (current_node->right) {
	  next_level->push_back(current_node->right);
	}

      }

      result.push_back(current_values);

      // update current_level by next_level
      vector<TreeNode*> *temp = current_level;
      current_level = next_level;
      next_level = current_level;
      next_level->clearn();

    }

    return result;

  }

}
