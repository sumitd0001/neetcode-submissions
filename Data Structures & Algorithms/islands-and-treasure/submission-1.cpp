class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int inf = 2147483647;
        queue<pair<int , int>> q;

        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        //int dist = 0;
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (const auto& d : dir) {
                int ni = i+d[0];
                int nj = j+d[1];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == inf) {
                    grid[ni][nj] = grid[i][j]+1;
                    q.push({ni, nj});
                }
            }
            //dist++;
        }
    }
};







































/*
class Solution {
public:

    //using bfs
    vector<vector<int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool isValid(int m, int n, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        return true;
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int inf = INT_MAX;
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) {
                if (grid[i][j] == 0) q.push({i, j});
            }
        }
        int dist = 1;
        while (!q.empty()) {
            int s = q.size();
            bool flag = false;

            for (int i = 0; i<s; ++i) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto& dir : directions) {
                    int nx = x + dir[0];
                    int ny = y + dir[1];
                    if (isValid(m, n, nx, ny) && grid[nx][ny] == inf) {
                        q.push({nx, ny});
                        grid[nx][ny] = dist;
                        flag = true;
                    }
                }
            }
            if (flag) dist++;
        }
    }
};
*/
