class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> uset;
        for (int i = 0; i<n; ++i) {
            uset.insert(nums[i]);
        }
        if (nums.size() == uset.size()) return false;
        else return true;
    }
};