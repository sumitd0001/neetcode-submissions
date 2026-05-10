class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int p = 0;
        int q = 1;
        while (p < n-3) {
            q = p+1;
            while (q < n-2) {
                long long x = (long long)target - nums[p] - nums[q];
                int i = q+1;
                int j = n-1;
                while (i < j) {
                    if (nums[i] + nums[j] == x) {
                        result.push_back({nums[p], nums[q], nums[i], nums[j]});
                        int y = i+1;
                        int z = j-1;
                        while (y < n && nums[y] == nums[i]) ++y;
                        while (z > i && nums[z] == nums[j]) --z;
                        i = y;
                        j = z;
                    }
                    else if (nums[i] + nums[j] < x) ++i;
                    else --j;
                }
                int r = q+1;
                while (r < n && nums[r] == nums[q]) ++r;
                q = r;
            }
            int s = p+1;
            while (s < n && nums[s] == nums[p]) ++s;
            p = s;
        }
        return result;
    }
};