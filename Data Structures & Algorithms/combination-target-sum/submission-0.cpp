class Solution {
public:

    void backtrack(int start, vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& current) {
        if (target == 0) {
            res.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i<nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(i, nums, target-nums[i], res, current);
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> current;
        backtrack(0, nums, target, res, current);
        return res;
    }
};
