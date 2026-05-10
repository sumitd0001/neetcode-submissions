class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j<n; ++j) {
            if (nums[i] == val && nums[j] != val) {
                swap(nums[i], nums[j]);
                ++i;
            }
            else if (nums[i] != val) ++i;
        }
        return i;
    }
};