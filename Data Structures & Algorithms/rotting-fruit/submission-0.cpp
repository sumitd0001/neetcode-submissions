class Solution {
public:

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool isValid(const int& m, const int& n, const int& i, const int& j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) if (grid[i][j] == 2) q.push({i, j});
        }
        int time = 0;
        while (!q.empty()) {
            int s = q.size();
            bool flag = false;
            for (int i = 0; i<s; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (const auto& dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];

                    if (isValid(m, n, nx, ny) && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        flag = true;
                    }
                }
            }
            if (flag) time++;
        }
        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) {
                if (grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};
