class Solution {
public:
    
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& state, int r, int c, int i, int j, bool& atl, bool& pac) {
        if (atl && pac) return;
        state[i][j] = 1;
        for (const auto& d : dir) {
            int ni = i+d[0];
            int nj = j+d[1];
            if (ni < 0 || nj < 0) pac = true;
            if (ni >= r || nj >= c) atl = true;
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && !state[ni][nj] && (heights[ni][nj] <= heights[i][j])) {
                dfs(heights, state, r, c, ni, nj, atl, pac);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int r = heights.size();
      int c = heights[0].size();
      
      vector<vector<int>> res;
      for (int i = 0; i<r; ++i) {
        for (int j = 0; j<c; ++j) {
            bool atl = false;
            bool pac = false;
            vector<vector<bool>> state(r, vector<bool>(c , 0));
            dfs(heights, state, r, c, i, j, atl, pac);
            if (atl && pac) res.push_back({i, j});
        }
      }
      return res;
    }
};
