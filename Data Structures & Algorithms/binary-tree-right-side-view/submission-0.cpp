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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        vector<int> result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int ls = q.size();

            for (int i = 0; i<ls; ++i) {
                TreeNode* f = q.front();
                if (i == ls-1) result.push_back(f->val);
                q.pop();
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
        }
        return result;
    }
};
