class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        int a;
        for (int i = 0; i<n; ++i) {
            if (c == 0) {
                a = nums[i];
                c++;
            }
            else if (nums[i] == a) c++;
            else c--;
        }
        return a;
    }





























    /*
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
    */
};