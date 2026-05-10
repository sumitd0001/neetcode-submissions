class Solution {
public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited) {
        visited[u] = true;
        for (const auto& x : adj[u]) if (!visited[x]) dfs(adj, x, visited);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        vector<bool> visited(n, false);
        int count = 0;
        for (const auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }

        for (int i = 0; i<n; ++i) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                count++;
            }
        }
        return count;
    }
};
