class Solution {
public:

   vector<vector<int>> directons{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

   void dfs(vector<vector<int>>& grid, int r, int c, int i, int j, int& area) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) return;
      
        grid[i][j] = 0;
        area++;
        for (const auto& d : directons) {
            int ni = i + d[0];
            int nj = j + d[1];
            dfs(grid, r, c, ni, nj, area);
        }
   }
  
   int maxAreaOfIsland(vector<vector<int>>& grid) {
       if (grid.empty()) return 0;
      
       int r = grid.size();
       int c = grid[0].size();
       int count = 0;
       int max_area = 0;

       for (int i = 0; i < r; ++i) {
           for (int j = 0; j < c; ++j) {
               
               if (grid[i][j] == 1) {
                int area = 0;
                dfs(grid, r, c, i, j, area);
                max_area = max(max_area, area);
                area = 0;
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
