class Solution {
public:

    //start from end, and keep largest at last
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int s = m+n-1;
        int i = m-1, j = n-1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) nums1[s--] = nums1[i--];
            else nums1[s--] = nums2[j--];
        }
        while (j >= 0) nums1[s--] = nums2[j--];
    }




































    /*
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1, j = n-1;
        int k = m+n-1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--]; 
            }
            else {
                nums1[k--] = nums2[j--]; 
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--]; 
        }
    }
    */
};