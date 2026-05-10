class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) return mid;
            else if (target < nums[mid]) {
                if (nums[mid-1] < target) return mid;
                else r = mid-1;
            }
            else {
                if (nums[mid+1] > target) return mid+1;
                else l = mid+1;
            }
        }
        if (l == 0) return 0;
        return n;
    }
};