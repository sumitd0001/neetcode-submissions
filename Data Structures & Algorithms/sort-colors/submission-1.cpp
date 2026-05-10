class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int i = 0;
        while (i <= r) {
            if (nums[l] == 0) {
                ++l;
                continue;
            }
            if (nums[r] == 2) {
                --r;
                continue;
            }
            if (nums[i] == 0 && nums[l] != 0 && i > l) {
                swap(nums[l], nums[i]);
                ++l;
                //++i;
            }
            else if (nums[i] == 2 && nums[r] != 2 && i < r) {
                swap (nums[i], nums[r]);
                --r;
            }
            else ++i;
        }
    }
};