class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n  = matrix.size();
        int m = matrix[0].size();

        int l = 0, r = n-1;
        while (l <= r) {
            int mid = l + (r-l)/2;

            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] > target) r = mid-1;
            else l = mid+1;
        }
        l--;
        if (l < 0) return false;
        int i = 0, j = m-1;
        while (i <= j) {
            int mid = i + (j-i)/2;

            if (matrix[l][mid] == target) return true;
            else if (matrix[l][mid] > target) j = mid-1;
            else i = mid+1;
        }
        return false;
    }
};
