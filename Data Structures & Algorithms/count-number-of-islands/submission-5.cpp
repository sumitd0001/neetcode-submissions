class Solution {
public:

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void dfs (vector<vector<char>>& grid, const int& r, const int& c, int i, int j) {
        if (i < 0 || i >=r || j < 0 || j >= c || grid[i][j] == '0') return;
        if (grid[i][j] == '2') return;
        grid[i][j] = '2';
        for (const auto& d : directions) {
            int ni = i + d[0];
            int nj = j + d[1];
            dfs(grid, r, c, ni, nj);
        }
    }

    void bfs (vector<vector<char>>& grid, const int& r, const int& c, int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '2';
        while (!q.empty()) {
            auto [ci, cj] = std::move(q.front());
            q.pop();

            for (const auto& d : directions) {
                int ni = ci + d[0];
                int nj = cj + d[1];

                if (ni < 0 || ni >= r || nj < 0 || nj >= c || grid[ni][nj] == '0') continue;
                else if (grid[ni][nj] == '2') continue;
                else {
                    grid[ni][nj] = '2';
                    q.push({ni, nj});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == '1') {
                    //dfs(grid, r, c, i, j);
                    bfs(grid, r, c, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};


































/*
class Solution {
public:
    // Define relative movements: Up, Down, Left, Right
    vector<vector<int>> directons{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, int r, int c, int i, int j) {
        // BASE CASE: Out of bounds OR hit water ('0')
        if (i < 0 || i >= r || j < 0 || j >= c || grid[i][j] == '0') return;
        
        // BASE CASE: Already visited this land ('2')
        if (grid[i][j] == '2') return;

        // MARK AS VISITED: Crucial to prevent infinite recursion/loops
        grid[i][j] = '2'; 

        // EXPLORE: Launch recursive calls in all 4 directions
        for (const auto& d : directons) {
            int ni = i + d[0];
            int nj = j + d[1];
            dfs(grid, r, c, ni, nj);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int r = grid.size();
        int c = grid[0].size();
        int count = 0;

        // GLOBAL SEARCH: Iterate through every cell in the matrix
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                // If we find unvisited land ('1'), it's a new island
                if (grid[i][j] == '1') {
                    // LOCAL EXPLORATION: 'Sink' the whole island using DFS
                    dfs(grid, r, c, i, j);
                    // Increment count only once per island found
                    count++;
                }
            }
        }
        return count;
    }
};
*/


































/*
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
*/
