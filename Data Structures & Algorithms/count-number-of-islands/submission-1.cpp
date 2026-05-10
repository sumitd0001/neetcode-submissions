class Solution {
public:

    using charM = vector<vector<char>>;
    using boolM = vector<vector<bool>>;
    using intM = vector<vector<int>>;
    
    intM directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs(charM& grid, boolM& visited, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0' || visited[i][j]) return;

        visited[i][j] = true;

        for (const auto& dir : directions) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            dfs(grid, visited, ni, nj, m, n);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        boolM visited(m, vector<bool>(n, false));

        for (int i = 0; i<m; ++i) {
            for (int j = 0; j<n; ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j, m, n);
                    islands++;
                }
            }
        }
        return islands;
    }
};
