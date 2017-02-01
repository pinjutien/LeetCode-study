/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  // http://www.geeksforgeeks.org/find-maximum-path-sum-in-a-binary-tree/
    int maxPathSum_util(TreeNode* root, int &current_max) {
        
        if (root == NULL) return 0;
        
        int left_sum = maxPathSum_util(root->left, current_max);
        int right_sum = maxPathSum_util(root->right, current_max);
        
        int max_single = max(max(left_sum, right_sum ) + root->val, root->val);
        
        int max_top = max(max_single, left_sum + right_sum + root->val);
        
        current_max = max(current_max, max_top);
        
        return max_single;
        
        
        
    }

    int maxPathSum(TreeNode* root) {
        int current_max = INT_MIN;
        maxPathSum_util(root, current_max);
        return current_max;        
    }
};
