class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set;
        int l = 0, r = 1;
        set.insert(nums[l]);
        while (r < n) {
            if (r-l <= k) {
                if (set.find(nums[r]) != set.end()) {
                    return true;
                }
                else {
                    set.insert(nums[r]);
                    r++;
                }
            } 
            else {
                set.erase(nums[l]);
                l++;
            }
        }
        return false;
    }
};