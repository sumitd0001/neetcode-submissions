// BFS - Start from ocean (uphill)
class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    // REUSABLE BFS ENGINE: Processes whatever source points were pre-loaded into 'q'
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>>& q, int r, int c) {
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            
            for (const auto& d : dir) {
                int ni = x + d[0];
                int nj = y + d[1];
                
                // UPHILL CONDITION: Only visit unvisited neighbors that are >= current height
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && !visited[ni][nj] && heights[ni][nj] >= heights[x][y]) {
                    // MARK ON PUSH: Sink the cell immediately to prevent redundant queue entries
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        // 1. Two separate bitmasks for Pacific and Atlantic reachability
        vector<vector<bool>> pacific_visted(r, vector<bool>(c, false));
        vector<vector<bool>> atlantic_visted(r, vector<bool>(c, false));

        // 2. MULTI-SOURCE SETUP: Use queues to collect all initial edge sources
        queue<pair<int, int>> q_pacific, q_atlantic;

        // Collect Vertical Edges (Left/Right)
        for (int i = 0; i < r; ++i) {
            if (!pacific_visted[i][0]) {
                q_pacific.push({i, 0});
                pacific_visted[i][0] = true;
            }
            if (!atlantic_visted[i][c-1]) {
                q_atlantic.push({i, c-1});
                atlantic_visted[i][c-1] = true;
            }
        }

        // Collect Horizontal Edges (Top/Bottom)
        for (int j = 0; j < c; ++j) {
            if (!pacific_visted[0][j]) {
                q_pacific.push({0, j});
                pacific_visted[0][j] = true;
            }
            if (!atlantic_visted[r-1][j]) {
                q_atlantic.push({r-1, j});
                atlantic_visted[r-1][j] = true;
            }
        }

        // 3. EXECUTE: Each BFS explores the entire ocean's reach in one "wave"
        bfs(heights, pacific_visted, q_pacific, r, c); 
        bfs(heights, atlantic_visted, q_atlantic, r, c); 

        // 4. INTERSECTION: Scan for coordinates that appear in both visited grids
        vector<vector<int>> res;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (pacific_visted[i][j] && atlantic_visted[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};


//DFS - Start from ocean (uphill)
/*
class Solution {
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // THE UPHILL DFS: 
    // Instead of water flowing down, we simulate the ocean "rising" up.
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int r, int c, int i, int j) {
        // Mark current cell as reachable by the specific ocean
        visited[i][j] = true;

        for (const auto& d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            // CONDITION: Next cell must be HIGHER or EQUAL (>=) to flow uphill.
            // Also ensures we don't revisit cells already reached by THIS ocean.
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && 
                !visited[ni][nj] && heights[ni][nj] >= heights[i][j]) {
                dfs(heights, visited, r, c, ni, nj);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r = heights.size();
        int c = heights[0].size();

        // Two independent bitmasks/grids to track reachability
        vector<vector<bool>> pac_visited(r, vector<bool>(c, false));
        vector<vector<bool>> atl_visited(r, vector<bool>(c, false));

        // 1. VERTICAL EDGES: Start DFS from Left (Pacific) and Right (Atlantic)
        for (int i = 0; i < r; ++i) {
            dfs(heights, pac_visited, r, c, i, 0);     // Left
            dfs(heights, atl_visited, r, c, i, c - 1); // Right
        }

        // 2. HORIZONTAL EDGES: Start DFS from Top (Pacific) and Bottom (Atlantic)
        for (int j = 0; j < c; ++j) {
            dfs(heights, pac_visited, r, c, 0, j);     // Top
            dfs(heights, atl_visited, r, c, r - 1, j); // Bottom
        }

        // 3. INTERSECTION: Any cell touched by BOTH ocean 'waves' is a result
        vector<vector<int>> res;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (pac_visited[i][j] && atl_visited[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
*/



//Backtracking
/*
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
*/





