class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int z = 0;
        int t = n-1;;
        int i = 0;
        while (i <= t) {
            if (nums[i] == 0) {
                swap(nums[i], nums[z]);
                z++;
                i++;
            }
            else if (nums[i] == 2) {
                swap(nums[t], nums[i]);
                t--;
            }
            else i++;
        }
    }





























    
    /*
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int i = 0;
        while (i <= r) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                ++i;
                ++l;
            }
            else if (nums[i] == 1) {
                ++i;
            }
            else if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                --r;
            }
        }
    }
    */
};