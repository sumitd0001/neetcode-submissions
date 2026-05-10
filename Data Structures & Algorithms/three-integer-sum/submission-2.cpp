class Solution {
public:
    
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j, k;
        int target = 0;
        vector<vector<int>> res;

        while (i < n-2) {
            int x = target - nums[i];
            j = i+1;
            k = n-1;
            while (j < k) {
                if (nums[j] + nums[k] == x) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k] == nums[k-1]) k--;
                    j++;
                    k--;
                }
                else if (nums[j] + nums[k] > x) --k;
                else ++j;
            }
            i++;
            while (i < n-2 && nums[i-1] == nums[i]) i++;
        }
        return res;
    }































    /*
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
            while (r < n && nums[k] == nums[r]) r++;
            k = r;
        }
        return result;
    }
    */
};
