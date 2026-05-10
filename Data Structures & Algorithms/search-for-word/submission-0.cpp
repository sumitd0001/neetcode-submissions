class Solution {
public:

    bool bt(vector<vector<char>>& board, string word, int m, int n, int r, int c, int i) {
        if (i == word.length()) return true;

        if (r < 0 || r > m-1 || c < 0 || c > n-1 || board[r][c] != word[i]) return false;

        char orig = board[r][c];
        board[r][c] = '#';
        bool found = bt(board, word, m, n, r+1, c, i+1) || bt(board, word, m, n, r-1, c, i+1) ||
                    bt(board, word, m, n, r, c+1, i+1) || bt(board, word, m, n, r, c-1, i+1);
        
        board[r][c] = orig;
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) {
                if (board[i][j] == word[0] && bt(board, word, m, n, i, j, 0)) return true;
            }
        }
        return false;
    }
};
