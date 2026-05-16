class Solution {
    public:

    vector<vector<int>> directions {{1,0}, {-1, 0}, {0, 1}, {0,-1}};

    void bfs (vector<vector<int>>& grid, int r, int c, int i, int j, int& x) {
        queue<pair<int, int>> q;
        q.push({i, j});

        while (!q.empty()) {
            auto& [ci, cj] = q.front();
            q.pop();
            //x += 4;
            grid[ci][cj] = 2;
            for (const auto& d : directions) {
                int ni = ci + d[0];
                int nj = cj + d[1];
                if (ni < 0 || ni >= r || nj < c || nj >= c || grid[ni][nj] == 0) x++;
                if (grid[ni][nj] == 2) continue;
                q.push({ni, nj});
            }
        }
    }

    void dfs (vector<vector<int>>& grid, int r, int c, int i, int j, int& x) {
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) {
            x++;
            return;
        }
        if (grid[i][j] == 2) return;
        grid[i][j] = 2;

        for (const auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];
            dfs(grid, r, c, ni, nj, x);
        }
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int p = 0;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == 1) {
                    int x = 0;
                    dfs(grid, r, c, i, j, x);
                    p += x;
                }
            }
        }
        return p;
    }
};








































/*
class Solution {
    public:
    
    int dfs (vector<vector<int>>& grid, int r, int c, int i, int j) {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0) return 1;

        if (grid[i][j] == 2) return 0;

        grid[i][j] = 2;

        return dfs(grid, r, c, i-1, j) +
                dfs(grid, r, c, i, j-1) +
                dfs(grid, r, c, i+1, j) +
                dfs(grid, r, c, i, j+1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int peri = 0;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == 1) {
                    peri += dfs(grid, r, c, i, j);
                }
            }
        }
        return peri;
    }
};
*/

/*
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int r , int c) {
        //you found a boundary, and we will add this to total perimeter
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == 0) return 1;
        //already visited
        if (grid[i][j] == 2) return 0;

        //marked as visited
        grid[i][j] = 2;

        //look in all 4 directions
        return  dfs(grid, i-1, j, r, c) +
                dfs(grid, i+1, j, r, c) +
                dfs(grid, i, j-1, r, c) +
                dfs(grid, i, j+1, r, c);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int perimeter = 0;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += dfs(grid, i, j, r, c);
                }
            }
        }
        return perimeter;
    }
};
*/


/*
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
*/