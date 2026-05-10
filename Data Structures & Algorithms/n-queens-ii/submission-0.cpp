class Solution {
public:
    void solve (int r, int n, vector<vector<string>>& res, vector<string>& current, vector<bool>& col, vector<bool>& posDiag, vector<bool>& negDiag) {
        if (r == n) {
            res.push_back(current);
            return;
        }

        for (int c = 0; c<n; ++c) {
            int nd = r-c+n;
            int pd = r+c;

            if (!col[c] && !negDiag[nd] && !posDiag[pd]) {
                col[c] = negDiag[nd] = posDiag[pd] = true;
                current[r][c] = 'Q';
                solve(r+1, n, res, current, col, posDiag, negDiag);
                col[c] = negDiag[nd] = posDiag[pd] = false;
                current[r][c] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> current;
        for (int i = 0; i<n; ++i) {
            string str;
            for (int j = 0; j<n; ++j) {
                str.push_back('.');
            }
            current.push_back(str);
        }
        vector<bool> col(n, 0);
        vector<bool> posDiag (2*n-1, 0);
        vector<bool> negDiag (2*n-1, 0);

        solve(0, n, res, current, col, posDiag, negDiag);
        return res.size();
    }
};