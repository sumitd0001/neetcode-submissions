class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int k = 0;
        while (k < n-2) {
            int x = target - nums[k];
            int i = k+1, j = n-1;
            while (i < j) {
                if (nums[i] + nums[j] == x) {
                    result.push_back({nums[k], nums[i], nums[j]});
                    int p = i+1;
                    while (nums[i] == nums[p]) ++p;
                    i = p;
                    int q = j;
                    while (nums[j] == nums[q]) --q;
                    j = q;
                }
                else if (nums[i] + nums[j] < x) {
                    i++;
                }
                else j--;
            }
            int r = k+1;
            while (nums[k] == nums[r]) r++;
            k = r;
        }
        return result;
    }
};
