class Solution {
public:
    
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int mn = nums[0];

        while (l <= r) {
            if (nums[l] <= nums[r]) {
                mn = min(mn, nums[l]);
                return mn;
            }
            int mid = l + (r-l)/2;
            mn = min(mn, nums[mid]);
            if (nums[mid] < nums[l]) {
                r = mid-1;
            }
            else l = mid+1;
        }
        return mn;
    }

































    /*
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int min = 1001;
        while (l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] < nums[r]) r = mid;
            else l = mid+1;
        }
        return nums[l];
    }
    */
};
