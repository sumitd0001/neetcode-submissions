class Solution {
public:

    void backtrack(vector<int>& nums, int start, vector<vector<int>>& res, vector<int>& current) {
        res.push_back(current);

        for (int i = start; i<nums.size(); ++i) {
            if (i > start && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            backtrack(nums, i+1, res, current);
            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        int start = 0;
        vector<int> current;
        sort(nums.begin(), nums.end());
        backtrack(nums, start, res, current);
        return res;
    }
};
