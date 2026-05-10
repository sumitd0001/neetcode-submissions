class Solution {
public : 

    vector<vector<int>> directions {{1, 0}, {-1, 0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int INF = 2147483647;
        queue<pair<int, int>> q;
        for (int i = 0; i<r; ++i) {
            for (int j = 0; j<c; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [i , j] = q.front();
            q.pop();

            for (const auto& d : directions) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == INF) {
                    grid[ni][nj] = grid[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }
    }
};




































/*
class Solution {
public:
    // Standard directions using your 'dir' naming
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int inf = 2147483647; // Represents "unvisited" treasure rooms
        queue<pair<int , int>> q;

        // 1. PRE-PROCESSING: Add ALL gates (0s) to the queue first.
        // This is what makes it "Multi-Source". All gates start at Level 0.
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // 2. BREADTH-FIRST SEARCH: Expand outward layer-by-layer
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for (const auto& d : dir) {
                int ni = i + d[0];
                int nj = j + d[1];

                // 3. BOUNDARY & INF CHECK:
                // We only visit a cell if it's within bounds AND is 'inf'.
                // If it's already been updated, the BFS guarantee says the 
                // first time we reached it was already the shortest path.
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == inf) {
                    
                    // 4. UPDATE DISTANCE:
                    // Current distance = Distance of parent + 1
                    grid[ni][nj] = grid[i][j] + 1;
                    
                    // 5. DISCOVERY: Mark as visited (by changing from inf) and push
                    q.push({ni, nj});
                }
            }
        }
    }
};
*/