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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> vec;
            for (int i = 0; i<levelsize; ++i) {
                TreeNode* f = q.front();
                vec.push_back(f->val);
                q.pop();
                if (f->left) q.push(f->left);
                if (f->right) q.push(f->right);
            }
            result.push_back(vec);
        }
        return result;
    }
};
