class Solution {
public:
    
    
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int longest = 0;
        int streak;
        int curr;

        for (auto& num : uset) {
            if (uset.find(num-1) == uset.end()) {
                streak = 1;
                curr = num+1;
                while (uset.find(curr) != uset.end()) {
                    streak++;
                    curr++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
    
    /*
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int mx = 0;
        int x ;
        int count = 0;
        int t = 0;
        for (auto v : s) {
            if (count == 0) {
                x = v;
                mx = 1;
                if (t < mx) t = mx;
            }
            else if (v == x+1) {
                mx++;
                x = v;
                if (t < mx) t = mx;
            }
            else {
                x = v;
                mx = 1;
            }
            count++;
        }
        return t;
    }
    */
};
