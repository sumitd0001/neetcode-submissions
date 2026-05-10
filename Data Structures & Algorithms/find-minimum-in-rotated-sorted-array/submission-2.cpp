class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        int min = 1001;
        while (l < r) {
            int mid = l + (r-l)/2;
            //cout<<"nums[l] : "<<nums[l]<<" mid : "<<nums[mid]<<" nums[r] : "<<nums[r]<<"\n";
            
            //if (min > nums[mid]) min = nums[mid];
            if (nums[mid] < nums[r]) r = mid;
            else l = mid+1;
        }
        return nums[l];
    }
};
