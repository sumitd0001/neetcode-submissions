class Solution {
public:
vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int iterativedfs(vector<vector<int>>& grid, int r, int c, int i, int j) {
    stack<pair <int, int>> st;
    
    // 1. DISCOVERY: Mark the starting cell as 0 immediately upon pushing
    st.push({i, j});
    grid[i][j] = 0; 
    
    int area = 0;
    while (!st.empty()) {
        int curri = st.top().first;
        int currj = st.top().second;
        st.pop();
        
        // 2. PROCESSING: Increment area once per unique pop
        area++;

        for (const auto& dir : directions) {
            int ni = curri + dir[0];
            int nj = currj + dir[1];
            
            // 3. BOUNDARY & LAND CHECK: Only look for unvisited land ('1')
            if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == 1) {
                
                /* CRITICAL LOGIC: 
                   Mark as 0 HERE (on push). This prevents other neighbors 
                   from seeing this same cell as '1' and pushing it again 
                   while it's still waiting in the stack.
                */
                grid[ni][nj] = 0; 
                st.push({ni, nj});
            }
        }
    }
    return area;
}

    int dfs(vector<vector<int>>& grid, int r, int c, int i, int j) {
        // BASE CASE: Return 0 for water, bounds, or visited land
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) {
            return 0;
        }
      
        // MARK AS VISITED: "Sink" the island
        grid[i][j] = 0;
        
        int currentArea = 1; // Start with 1 for the current cell
        
        // AGGREGATE: Add the area returned from all 4 directions
        for (const auto& d : directions) {
            currentArea += dfs(grid, r, c, i + d[0], j + d[1]);
        }
        
        return currentArea;
    }
  
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int r = grid.size(), c = grid[0].size();
        int max_area = 0;

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 1) {
                    // The DFS call now returns the total size directly
                    max_area = max(max_area, iterativedfs(grid, r, c, i, j));
                }
            }
        }
        return max_area;
    }
};









































/*
class Solution {
public:
    using intM = vector<vector<int>>;
    using boolM = vector<vector<bool>>;

    void dfs (intM& grid, boolM& visited, int i, int j, int m, int n, int& count) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) return;

        visited[i][j] = true;
        count++;

        dfs(grid, visited, i+1, j, m, n, count);
        dfs(grid, visited, i-1, j, m, n, count);
        dfs(grid, visited, i, j+1, m, n, count);
        dfs(grid, visited, i, j-1, m, n, count);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        boolM visited(m, vector<bool>(n, 0));
        int mx = 0;
        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int count = 0;
                    dfs(grid, visited, i, j, m, n, count);
                    mx = max(mx, count);
                }
            }
        }
        return mx;
    }
};
*/
