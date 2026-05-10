class Solution {
public:

    /*
    Performance Ranking for Concatenation:
    insert() or Iterator Constructor: Best. Uses block-memory moves (memcpy/memmove).
    std::copy with reserve: Good. Clearer intent.
    */

    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        //memmove / memcpy operation
        std::vector<int> vec (nums.begin(), nums.end());
        //Reserve the rest (no-op because size is n, we want 2n)
        vec.reserve(2*n);
        //One internal memmove/memcpy for the second half
        vec.insert(vec.end(), nums.begin(), nums.end());
        return vec;
    }

    /*
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(2*n, 0);
        for (int i = 0; i<n; ++i) { result[i] = nums[i]; result[i+n] = nums[i]; }
        return result;
    }
    */

    /*
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(2*n, 0);

        for (int i = 0; i<n; ++i) {
            result[i] = nums[i];
            result[i+n] = nums[i]; 
        }

        return result;
    }
    */
};