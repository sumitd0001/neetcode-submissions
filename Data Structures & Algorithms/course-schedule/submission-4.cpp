class Solution {
public:
    // 3 States: 0 = Unvisited, 1 = Visiting (In Stack), 2 = Visited (Fully Processed)
    bool hasCycle(vector<vector<int>>& adj, int u, vector<int>& state) {
        // BASE CASES: Centralized logic
        if (state[u] == 1) return true;  // Found a back-edge! (Cycle)
        if (state[u] == 2) return false; // Already verified this path is clean

        // 1. MARK AS VISITING
        state[u] = 1;

        // 2. EXPLORE NEIGHBORS
        for (const auto& neighbor : adj[u]) {
            if (hasCycle(adj, neighbor, state)) return true;
        }

        // 3. MARK AS VISITED (Backtrack/Finish)
        state[u] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& edge : prerequisites) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> state(numCourses, 0);
        for (int i = 0; i < numCourses; ++i) {
            // Only launch DFS for fresh nodes
            if (state[i] == 0 && hasCycle(adj, i, state)) return false;
        }

        return true;
    }
};

/*
class Solution {
public:

    bool hasCycle(vector<vector<int>>& adj, int u, vector<int>& state) {
        if (state[u] == 1) return true;
        if (state[u] == 2) return false;

        state[u] = 1;
        for (const auto& x : adj[u]) {
            if (hasCycle(adj, x, state)) return true;
        }
        state[u] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for (auto& vec : prerequisites) {
            adj[vec[0]].push_back(vec[1]);
        }
        vector<int> state(numCourses, 0);
        for (int i = 0; i<numCourses; ++i)
            if (state[i] == 0) if (hasCycle(adj, i, state)) return false;

        return true;
    }
};
*/
