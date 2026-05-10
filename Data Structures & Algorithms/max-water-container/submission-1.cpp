class Solution {
public:
    
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n-1;
        int max_area = 0;
        while (l < r) {
            int curr_area;
            if (heights[l] < heights[r]) {
                curr_area = heights[l]*(r - l);
                l++;
            }
            else {
                curr_area = heights[r]*(r - l);    
                r--;
            }
            if (max_area < curr_area) max_area = curr_area;
        }
        return max_area;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
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
    */
};
