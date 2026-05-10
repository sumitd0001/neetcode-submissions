class Solution {
public:

    int minimumDelay(const vector<vector<pair<int, int>>>& adj, const int& k, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
        vector<int> dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k] = 0;

        while(!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            if (d > dist[node]) continue;
            for (const auto& [next, weight] : adj[node]) {
                if (dist[node] + weight < dist[next]) {
                    dist[next] = dist[node] + weight;
                    pq.push({dist[next], next});
                }
            }
        }


        int ans = 0;
        for (int i = 1; i<=n; ++i) {
            if (dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1, vector<pair<int, int>>());

        for (const auto& vec : times) adj[vec[0]].push_back({vec[1], vec[2]});

        return minimumDelay(adj, k, n);
    }
};
