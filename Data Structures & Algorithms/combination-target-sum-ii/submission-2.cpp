class Solution {
public:

    void backtrack(int start, vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& current) {
        if (target == 0) {
            res.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i<nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) continue;
            if (nums[i] > target) break;
            current.push_back(nums[i]);
            backtrack(i+1, nums, target-nums[i], res, current);
            current.pop_back();
        }
    }   

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(0, candidates, target, res, current);
        return res;
    }
};
