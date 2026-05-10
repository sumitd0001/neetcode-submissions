class Solution {
public:

    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i<n; ++i) {
            if (nums[i] != val) swap(nums[i], nums[pos++]); 
        }
        return pos;
    }








































    /*
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int pos = 0;
        for (int i = 0; i<n; ++i)
            if (nums[i] != val) swap(nums[i], nums[pos++]);
        return pos;
    }
    */






    /*
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;

        for (int j = 0; j<n; ++j) {
            if (nums[j] != val) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        return i;
    }
    */





























    /*
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j<n; ++j) {
            if (nums[i] == val && nums[j] != val) {
                swap(nums[i], nums[j]);
                ++i;
            }
            else if (nums[i] != val) ++i;
        }
        return i;
    }
    */
};