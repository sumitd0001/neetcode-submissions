class Solution {
public:

    int minCostPrim(unordered_map<int, vector<pair<int, int>>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);

        //min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        int res = 0;
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (visited[u]) continue;
            visited[u] = true;
            res += d;
            for (const auto& [v, dist] : adj[u]) {
                if (!visited[v]) {
                    pq.push({dist, v});
                }
            }
        }
        return res;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 1) return 0;
        unordered_map<int, vector<pair<int, int>>> adj;

        for (int i = 0; i<n; ++i) {
            for (int j = i+1; j<n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adj[i].push_back({j, dist});
                adj[j].push_back({i, dist});
            }
        }
        return minCostPrim(adj);
    }
};
