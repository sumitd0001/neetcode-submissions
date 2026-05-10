class Solution {
public : 
    vector<vector<int>> dir{{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int fresh = 0;

        // 1. PRE-PROCESSING: Find all starting rotten oranges (sources)
        // and count fresh oranges so we can verify if all rot at the end.
        queue<pair<int, int>> q;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        // If there are no fresh oranges, 0 minutes have passed.
        if (fresh == 0) return 0;

        bool flag;
        int time_elapsed = 0;
        int fresh_into_rotten = 0;

        // 2. LEVEL-ORDER TRAVERSAL: Process BFS layer by layer
        while (!q.empty()) {
            int s = q.size(); // Number of oranges currently rotting at this minute
            flag = false;     // Track if any NEW orange rots during this minute
            
            for (int k = 0; k < s; ++k) {
                auto [i, j] = q.front();
                q.pop();

                for (const auto& d : dir) {
                    int ni = i + d[0];
                    int nj = j + d[1];

                    // 3. BOUNDARY & FRESH CHECK: Only fresh oranges (1) can rot
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c && grid[ni][nj] == 1) {
                        flag = true; 
                        grid[ni][nj] = 2; // Mark as rotten (visited)
                        fresh_into_rotten++;
                        q.push({ni, nj});
                    }
                }
            }
            // 4. TIME INCREMENT: Only add a minute if we actually spread the rot
            if (flag) time_elapsed++;
        }

        // 5. FINAL CHECK: If our count matches original fresh count, return time; else -1
        return (fresh_into_rotten == fresh) ? time_elapsed : -1;
    }
};