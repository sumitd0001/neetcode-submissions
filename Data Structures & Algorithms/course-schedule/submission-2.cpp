class Solution {
public:

    bool hasCycle(const vector<vector<int>>& adj, const int& numCourses, vector<int>& state, int u) {
        if (state[u] == 1) return true;
        if (state[u] == 2) return false;

        state[u] = 1;

        for (const auto& x : adj[u]) {
            if (state[x] == 0) {
                if (hasCycle(adj, numCourses, state, x)) return true;
            }
            else if (state[x] == 1) return true;
        }
        state[u] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> state(numCourses, 0);

        vector<vector<int>> adj(numCourses, vector<int>());

        for (const auto& vec : prerequisites) {
            adj[vec[0]].push_back(vec[1]);
        }

        for (int i = 0; i<numCourses; ++i) {
            if (state[i] == 0) {
                if (hasCycle(adj, numCourses, state, i)) return false;
            }
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
