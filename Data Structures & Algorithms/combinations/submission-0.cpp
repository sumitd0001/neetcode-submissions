class Solution {
public:

    //nums[1, 2, 3, 4, 5, 6, .......n];

    void backtrack(int& n, int& k, vector<vector<int>>& res, int start, vector<int>& current) {
        if (current.size() == k) {
            res.push_back(current);
            return;
        }

        for (int i = start; i<=n; ++i) {
            current.push_back(i);
            backtrack(n, k, res, i+1, current);
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        int start = 1;
        vector<int> current;
        backtrack(n, k, res, start, current);
        return res;
    }
};