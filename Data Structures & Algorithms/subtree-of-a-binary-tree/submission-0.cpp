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
    bool sameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;

        if (p && q && p->val == q->val) return sameTree(p->left, q->left) && sameTree(p->right, q->right);
        return false;
    }

    bool isSubtree(TreeNode* p, TreeNode* q) {
        if (!q) return true;
        if (!p) return false;

        if (sameTree(p, q)) return true;
        return isSubtree(p->left, q) || isSubtree(p->right, q);
    }
};
