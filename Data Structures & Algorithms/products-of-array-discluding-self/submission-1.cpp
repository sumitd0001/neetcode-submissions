class Solution {
public:

    //
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> pp(n);
        pp[0] = 1;
        
        for (int j = 1; j<n; ++j) pp[j] = pp[j-1]*nums[j-1];
        
        int sp = 1;
        for (int k = n-2; k >= 0; --k) { sp *= nums[k+1]; pp[k] *= sp; }

        return pp;
    }
};
