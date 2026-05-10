//BFS - Start from ocean (uphill)
class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int r, int c) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (const auto& d : dir) {
                int ni = x+d[0];
                int nj = y+d[1];
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && !visited[ni][nj] && heights[ni][nj] >= heights[x][y]) {
                    q.push({ni, nj});
                    visited[ni][nj] = true;
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        vector<vector<bool>> pacific_visted(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic_visted(r, vector<bool>(c, false));

        //use queue here to insert compete edge once and then call bfs on that, multi-source bfs
        queue<pair<int, int>> q_pacific, q_atlantic;


       for (int i = 0; i<r; ++i) {
            if (!pacific_visted[i][0]) {
                q_pacific.push({i, 0});
                pacific_visted[i][0] = true;
            }
            if (!atlantic_visted[i][c-1]) {
                q_atlantic.push({i, c-1});
                atlantic_visted[i][c-1] = true;
            }
        }

        for (int j = 0; j<c; ++j) {
            if (!pacific_visted[0][j]) {
                q_pacific.push({0, j});
                pacific_visted[0][j] = true;
            }
            if (!atlantic_visted[r-1][j]) {
                q_atlantic.push({r-1, j});
                atlantic_visted[r-1][j] = true;
            }
        }

        bfs(heights, pacific_visted, q_pacific, r, c); // pacific
        bfs(heights, atlantic_visted, q_atlantic, r, c); // atlantic

        vector<vector<int>> res;

        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (pacific_visted[i][j] && atlantic_visted[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};







