class Solution {
public:
    void solve (int r, int n, vector<string>& current, vector<vector<string>>& res, vector<bool>& col,
        vector<bool>& diag1, vector<bool>& diag2) {
        if (r == n) {
            res.push_back(current);
            return;
        }

        for (int c = 0; c<n; ++c) {
            int d1 = r-c+n;
            int d2 = r+c;

            if (!col[c] && !diag1[d1] && !diag2[d2]) {
                current[r][c] = 'Q';
                col[c] = diag1[d1] = diag2[d2] = true;

                solve(r+1, n, current, res, col, diag1, diag2);

                current[r][c] = '.';
                col[c] = diag1[d1] = diag2[d2] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
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
        vector<bool> diag1(2*n-1, 0);
        vector<bool> diag2(2*n-1, 0);
        solve(0, n,  current, res, col, diag1, diag2);
        return res;
    }
};
