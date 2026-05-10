class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n-1;
        int max = 0;
        while (l < r) {
            int cur = 0;
            if (heights[l] < heights[r]) {
                cur = heights[l]* (r-l);
                ++l;
            }
            else {
                cur = heights[r]* (r-l);
                --r;
            }
            if (max < cur) max = cur;
        }
        return max;
    }
};
