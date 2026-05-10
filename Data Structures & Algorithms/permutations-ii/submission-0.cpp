class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& current, vector<bool>& used) {
        if (current.size() == nums.size()) {
            res.push_back(current);
            return;
        }

        for (int i = 0; i<nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            /*
            if (!used[i] && i > 0 && nums[i] == nums[i-1]) {
                used[i] = true;
                continue;
            }
            */
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, res, current, used);
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current;
        vector<bool> used(nums.size(), 0);
        sort(nums.begin(), nums.end());
        backtrack(nums, res, current, used);
        return res;
    }
};