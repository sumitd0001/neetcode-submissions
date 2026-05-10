class Solution {
public:
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> uset;
        int l = 0;
        int r = 1;
        uset.insert(nums[l]);
        while (r < n && (r-l) <= k) {
            if (uset.count(nums[r])) return true;
            else uset.insert(nums[r]);
            r++;
        }
        while (r < n) {
            uset.erase(nums[l]);
            l++;
            if (uset.count(nums[r])) return true;
            else uset.insert(nums[r]);
            r++;
        }
        return false;
    }




































    /*
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int> set;
        int l = 0, r = 0;
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
    */
};