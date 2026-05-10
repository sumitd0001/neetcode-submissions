class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int a = nums[0];
        int count = 1;
        for (int i = 1; i<n; ++i) {
            if (count == 0) {
                a = nums[i];
                count++;
                }
            else if (nums[i] == a) count++;
            else count--;
        }
        return a;
    }
};