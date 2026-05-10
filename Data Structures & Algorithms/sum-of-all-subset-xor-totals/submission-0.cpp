class Solution {
public:

 void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    // Every state we land on is a valid subset, so we save it immediately
    result.push_back(current); 

    for (int i = start; i < nums.size(); i++) {
        // 1. CHOOSE
        current.push_back(nums[i]);

        // 2. EXPLORE (Notice we pass i + 1, so we don't pick the same number again)
        backtrack(i + 1, nums, current, result);

        // 3. UN-CHOOSE (Backtrack)
        current.pop_back(); 
    }
}

    int subsetXORSum(vector<int>& nums) {
        vector<int> current;
        int start = 0;
        vector<vector<int>> result;
        backtrack(start, nums, current, result);
        int xor_res = 0;
        int sum = 0;
        for (auto vec : result) {
            xor_res = 0;
            for (auto x : vec) {
                xor_res =  xor_res^x;
            }
            sum += xor_res;
        }
        return sum;
    }
};