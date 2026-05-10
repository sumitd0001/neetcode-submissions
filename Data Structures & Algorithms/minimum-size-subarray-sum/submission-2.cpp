class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minsize = n+1;
        int l = 0, r = 0;
        int sum = 0;
        while (r < n) {
            //if (sum < target) 
            sum += nums[r];
            //if (sum >= target) minsize = min(minsize, r-l+1);
            while (sum - nums[l] >= target) {
                sum -= nums[l];
                l++;
            }
            if (sum >= target) minsize = min(minsize, r-l+1);
            r++;
        }
        return minsize > n ? 0 : minsize;
    }
};