class Solution {
public:

    //Quick sort

    int partition(vector<int>& nums, int l, int h) {
        int pivot = l + (h-l)/2;
        int val = nums[pivot];

        int i = l-1;
        int j = h+1;

        while (1) {
            do { i++; } while (nums[i] < val);
            do { j--; } while (nums[j] > val);

            if (i >= j) return j;
            swap(nums[i], nums[j]);
        }
    }
    
    void quickSort(vector<int>& nums, int l, int h) {
        if (l < h) {
            int p = partition(nums, l , h);
            quickSort(nums, l, p);
            quickSort(nums, p+1, h);
        }
    }
    

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        //partition(nums, 0, nums.size()-1);
        return nums;
    }
};