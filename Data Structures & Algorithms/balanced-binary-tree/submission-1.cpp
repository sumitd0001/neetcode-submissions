/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public: 
    
    int heightDiff(TreeNode* root) {
        if (!root) return 0;
        return max(heightDiff(root->left), heightDiff(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        int l = heightDiff(root->left);
        int r = heightDiff(root->right);
        if (abs(l - r) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
    
};
