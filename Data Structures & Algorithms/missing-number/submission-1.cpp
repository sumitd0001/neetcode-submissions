class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int s1 = (n+1)*n/2;
        int s2 = 0;
        for (auto x : nums) s2 += x;
        return s1-s2;
    }
};
