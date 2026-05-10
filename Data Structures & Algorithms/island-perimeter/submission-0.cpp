class Solution {
public:

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j, int r , int c) {
        if (i  < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) return 1;
        if (visited[i][j]) return 0;

        visited[i][j] = true;

        return dfs(grid, visited, i, j+1, r, c) + dfs(grid, visited, i, j-1, r, c) + dfs(grid, visited, i+1, j, r, c) 
            + dfs(grid, visited, i-1, j, r, c);
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == 1) return dfs(grid, visited, i, j, r, c);
            }
        }
        return 0;
    }
};