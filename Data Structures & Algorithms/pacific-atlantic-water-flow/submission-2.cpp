class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // DFS with Backtracking/State tracking
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& state, int r, int c, int i, int j, bool& atl, bool& pac) {
        // Optimization: if both oceans are found, stop searching this path
        if (atl && pac) return;

        // Mark current cell as visited for this specific search
        state[i][j] = 1;

        for (const auto& d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            // 1. OCEAN CHECKS: Check if moving in this direction hits a boundary
            if (ni < 0 || nj < 0) pac = true;       // Top/Left = Pacific
            if (ni >= r || nj >= c) atl = true;    // Bottom/Right = Atlantic

            // 2. FLOW CHECK: Valid within bounds, not visited in this path, and downhill/flat
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && !state[ni][nj] && (heights[ni][nj] <= heights[i][j])) {
                dfs(heights, state, r, c, ni, nj, atl, pac);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      int r = heights.size();
      int c = heights[0].size();
      vector<vector<int>> res;

      // GLOBAL SCAN: Attempt a search from every single cell
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            bool atl = false;
            bool pac = false;
            
            // 3. MEMORY HEAVY: Creating a new visited matrix for every cell
            vector<vector<bool>> state(r, vector<bool>(c , 0));
            
            dfs(heights, state, r, c, i, j, atl, pac);
            
            // 4. RESULT COLLECTION: If both ocean flags were tripped
            if (atl && pac) res.push_back({i, j});
        }
      }
      return res;
    }
};