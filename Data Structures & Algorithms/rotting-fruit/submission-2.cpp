class Solution {
public : 
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int fresh = 0;

        queue<pair<int, int>> q;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }
        bool flag;
        int time_elapsed = 0;
        int fresh_into_rotten = 0;
        while (!q.empty()) {
            int s = q.size();
            flag = false;
            //cout<<"s : "<<s<<"\n";
            for (int k = 0; k<s; ++k) {
                auto [i, j] = q.front();
                //cout<<"i : "<<i<<" j : "<<j<<"\n";
                q.pop();
                for (const auto& d : dir) {
                    int ni = i+d[0];
                    int nj = j+d[1];
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == 1) {
                        flag = true;
                        grid[ni][nj] = 2;
                        fresh_into_rotten++;
                        q.push({ni, nj});
                    }
                }
            }
            if (flag) time_elapsed++;
        }
        return (fresh_into_rotten == fresh) ? time_elapsed : -1;
    }
};





































/*
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
        int fresh{};
        queue<pair<int, int>> q;
        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }

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
                        fresh--;
                    }
                }
            }
            if (flag) time++;
        }
        return (fresh == 0) ? time : -1;
    }
};
*/
